#include "main.h"
//#include "model_chunk1.h"
//#include "model_chunk2.h"
//#include "model_chunk3.h"
#include "mnistMulti_chunk1.h"
#include "mnistMulti_chunk2.h"
#include "mnistMulti_chunk3.h"
#include "tensorflow/lite/micro/kernels/all_ops_resolver.h"
#include "tensorflow/lite/micro/micro_error_reporter.h"
#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/schema/schema_generated.h"
#include "tensorflow/lite/version.h"
#include <math.h>
#include <stdio.h>

#define BUFFER_SIZE1 32*1024
uint8_t tensor_arena1[BUFFER_SIZE1] __attribute__((aligned(16)));
#define BUFFER_SIZE2 32*1024
uint8_t tensor_arena2[BUFFER_SIZE2] __attribute__((aligned(16)));
#define BUFFER_SIZE3 32*1024
uint8_t tensor_arena3[BUFFER_SIZE3] __attribute__((aligned(16)));

class Names
{
public:
    tflite::ErrorReporter* error_reporter = nullptr;
    const tflite::Model* model = nullptr;
    tflite::MicroInterpreter* interpreter = nullptr;
    TfLiteTensor* model_input = nullptr;
    TfLiteTensor* model_output = nullptr;

    // Create an area of memory to use for input, output, and intermediate arrays.
    // Finding the minimum value for your model may require some trial and error.
//    uint32_t kTensorArenaSize = BUFFER_SIZE;
    uint8_t *tensor_arena;
    uint32_t kTensorArenaSize = 0;

    tflite::MicroErrorReporter micro_error_reporter;
    tflite::ops::micro::AllOpsResolver resolver;

    Names()
    {

    }

    int setup(const unsigned char* model_set, uint8_t model_idx, uint8_t *p_tensor_arena, uint32 tensor_arena_size)
    {

    	printf("Model Number: %d\r\n", model_idx);
    	tensor_arena = p_tensor_arena;
    	kTensorArenaSize = tensor_arena_size;

//      	static tflite::MicroErrorReporter micro_error_reporter;
      	error_reporter = &micro_error_reporter;

      	// Map the model into a usable data structure. This doesn't involve any
      	// copying or parsing, it's a very lightweight operation.
    //    model = tflite::GetModel(fc_model);
      	model = tflite::GetModel(model_set);

      	if(model->version() != TFLITE_SCHEMA_VERSION)
      	{
      		TF_LITE_REPORT_ERROR(error_reporter,
      	                         "Model provided is schema version %d not equal "
      	                         "to supported version %d.",
    							 model->version(), TFLITE_SCHEMA_VERSION);
      	    return 0;
      	}

      	// This pulls in all the operation implementations we need.
//      	static tflite::ops::micro::AllOpsResolver resolver;

      	// Build an interpreter to run the model with.
      	if (model_idx == 0)
		{
			static tflite::MicroInterpreter static_interpreter1(model, resolver, tensor_arena, kTensorArenaSize, error_reporter);
			interpreter = &static_interpreter1;
		}
      	else if (model_idx == 1)
      	{
			static tflite::MicroInterpreter static_interpreter2(model, resolver, tensor_arena, kTensorArenaSize, error_reporter);
			interpreter = &static_interpreter2;
		}
      	else if (model_idx == 2)
		{
			static tflite::MicroInterpreter static_interpreter3(model, resolver, tensor_arena, kTensorArenaSize, error_reporter);
			interpreter = &static_interpreter3;
		}

      	// Allocate memory from the tensor_arena for the model's tensors.
      	TfLiteStatus allocate_status = interpreter->AllocateTensors();
      	if (allocate_status != kTfLiteOk)
      	{
      	    TF_LITE_REPORT_ERROR(error_reporter, "AllocateTensors() failed");
      	    return 0;
      	}

      	return 0;
    }
//    int loop(void);
};

Names names1;
Names names2;
Names names3;

float compute_entropy_normalized(float *probs, int len);

float compute_entropy_normalized(float *probs, int len)
{
	float entropy = 0.0;
	for (int i=0; i < len; i++)
	{
		entropy += probs[i] * log(probs[i]);
	}
	entropy /= log(len);
	return -entropy;
}

void unit_test_entropy()
{
	float probs[] = {0.3333,0.3333,0.3333};
//	float probs[] = {0.25,0.25,0.25,0.25};
	float entropy;
	entropy = compute_entropy_normalized(probs, sizeof(probs)/sizeof(probs[0]));

	fprintf(stderr, "Test Entropy=%f\r\n", entropy);
}

int setup1(void)
{
//	names1.setup(fc_model, 0, tensor_arena1, sizeof(tensor_arena1));
//	names2.setup(conv_model, 1, tensor_arena2, sizeof(tensor_arena2));

//	names1.setup(model_chunk1, 0, tensor_arena1, sizeof(tensor_arena1));
	names1.setup(mnistMulti_chunk1, 0, tensor_arena1, sizeof(tensor_arena1));
//	names1.setup(pruned_model_chunk1, 0, tensor_arena1, sizeof(tensor_arena1));

//	names2.setup(model_chunk2, 1, tensor_arena2, sizeof(tensor_arena2));
	names2.setup(mnistMulti_chunk2, 1, tensor_arena2, sizeof(tensor_arena2));
//	names2.setup(pruned_model_chunk2, 1, tensor_arena2, sizeof(tensor_arena2));

//	names3.setup(model_chunk3, 2, tensor_arena3, sizeof(tensor_arena3));
	names3.setup(mnistMulti_chunk3, 2, tensor_arena3, sizeof(tensor_arena3));
//	names3.setup(pruned_model_chunk3, 2, tensor_arena3, sizeof(tensor_arena3));
	return 0;
}

#define NUM_TEST_SAMPLES 4
extern unsigned char mnist_1_21[];
extern unsigned char mnist_6_374[];
extern unsigned char mnist_idx18[];
extern unsigned char mnist_idx68[];

int wait_and_sleep(float target_voltage)
{
	int max_trials = 3;
	int try_idx = 0;
	float sys_voltage = 0.0;

	while (1)
	{
		// read ADC voltage
		stop_mode2_duration(ADC_MEASURE_DELAY);
		sys_voltage = adc_ref_internal_read();
		if (sys_voltage < target_voltage)
		{
			if (try_idx >= max_trials)
			{
				printf("charging FAILED, final=%.2f, target=%.2f, try %d\r\n", sys_voltage, target_voltage, max_trials);
				return -1;
			}
			else
			{
				printf("wait charging, now=%.2f, target=%.2f, try %d/%d\r\n", sys_voltage, target_voltage, try_idx, max_trials);
			}
		}
		else
		{
			printf("charging ok, now=%.2f, target=%.2f, try %d/%d\r\n", sys_voltage, target_voltage, try_idx, max_trials);
			return 0;
		}

		stop_mode2_duration(20000);

		try_idx++;
	}
	return -1;
}


void incremental_inference_with_voltage(image_t image, tflite::MicroInterpreter* interpreter1, tflite::ErrorReporter* error_reporter1,
												 tflite::MicroInterpreter* interpreter2, tflite::ErrorReporter* error_reporter2,
												 tflite::MicroInterpreter* interpreter3, tflite::ErrorReporter* error_reporter3,
												 float *probs, int32_t *exit, float *entropy, uint32_t *inference_time_total) {
	int image_size = MODEL_IMAGE_WIDTH * MODEL_IMAGE_HEIGHT * NUM_CHANNELS;
	//int feature1_size = 14*14*5; // Commented out by me
	//int feature2_size = 7*7*10; // Commented out by me
	float entropy1 = 0, entropy2 = 0, entropy3 = 0;
//	float entropy_thresholds[] = {0.1, 0.1, 0.1};
	float entropy_thresholds[] = {0.2, 0.2, 0.2};
//	float entropy_thresholds[] = {-100.0, -100.0, -100.0};
	float voltage_thresholds[] = {3.8, 3.8, 3.8};
	//float sys_voltage = 0.0; // Commented out by me
	int charge_status;
	uint32_t start, inference_time1, inference_time2, inference_time3;

    // Obtain pointers to the model's input and output tensors
    TfLiteTensor *input1 = interpreter1->input(0);
    TfLiteTensor *output1_mid_feature = interpreter1->output(0);
    TfLiteTensor *output1_probs = interpreter1->output(1);

    // Copy data from image type
    for (int i = 0; i < image_size; i++) {
    	input1->data.f[i] = image.data[i] / 255.0f;
    }

    // check voltage
    charge_status = wait_and_sleep(voltage_thresholds[0]);
	if (charge_status == -1)
	{
		*exit = -1;
		printf("Low energy! No Results can be obtained! Aborting this event\r\n");
		return;
	}

    error_reporter1->Report("Invoking interpreter1");
    start = HAL_GetTick();
	if (kTfLiteOk != interpreter1->Invoke())
	{
		error_reporter1->Report("Error1");
	}

	// ADDED
	float sum = 0.0;
//	float *probsnew = output1_probs->data.f;
//	printf("0: %.4f, 1: %.4f, 2: %.4f, 3: %.4f, 4: %.4f, 5: %.4f, 6: %.4f, 7: %.4f, 8: %.4f, 9: %.4f \r\n", probsnew[0], probsnew[1], probsnew[2], probsnew[3], probsnew[4], probsnew[5], probsnew[6], probsnew[7], probsnew[8], probsnew[9]);

	inference_time1 = HAL_GetTick() - start;
	*inference_time_total += inference_time1;
	// compute confidence 1
	entropy1 = compute_entropy_normalized(output1_probs->data.f, kCategory);

//	error_reporter1->Report("Showing results1");

	fprintf(stderr, "duration1=%ld ms\r\n", inference_time1);
	for (int i=0; i < kCategory; i++)
	{
//		error_reporter->Report("Label=%d, Prob=%f", i, output->data.f[i]);
		fprintf(stderr, "[%d, Prob=%.4f] ", i, output1_probs->data.f[i]);
		sum += output1_probs->data.f[i];
	}
	fprintf(stderr, "\r\n");
	fprintf(stderr, "entropy1=%f\r\n", entropy1);
	printf("Sum: %f\r\n", sum);
	sum = 0.0;
	// 11.041758

	if (entropy1 < entropy_thresholds[0])
	{
		memcpy(probs, output1_probs->data.f, kCategory*sizeof(probs[0]));
		*exit = 1;
		*entropy = entropy1;
		return;
	}

	// accumulate enough Voltage before proceeding
//	stop_mode2_duration(ADC_MEASURE_DELAY);
//	sys_voltage = adc_ref_internal_read();
	charge_status = wait_and_sleep(voltage_thresholds[1]);
	if (charge_status == -1)
	{
		memcpy(probs, output1_probs->data.f, kCategory*sizeof(probs[0]));
		*exit = 1;
		*entropy = entropy1;
		printf("Existing from exit 1 due to low Energy. Results may be INACCURATE!\r\n");
		return;
	}

	// model 2
	// Obtain pointers to the model's input and output tensors
	TfLiteTensor *input2 = interpreter2->input(0);
	TfLiteTensor *output2_mid_feature = interpreter2->output(0);
	TfLiteTensor *output2_probs = interpreter2->output(1);
//	for (int i = 0; i < feature1_size; i++) {
//		input2->data.f[i] = output1_mid_feature->data.f[i];
//	}
	// avoid copying
	input2->data.f = output1_mid_feature->data.f;

	error_reporter2->Report("Invoking interpreter2");
	start = HAL_GetTick();
	if (kTfLiteOk != interpreter2->Invoke())
	{
		error_reporter2->Report("Error2");
	}
	inference_time2 = HAL_GetTick() - start;
	*inference_time_total += inference_time2;
	// compute confidence 2
	entropy2 = compute_entropy_normalized(output2_probs->data.f, kCategory);

//	error_reporter2->Report("Showing results2");

	fprintf(stderr, "duration2=%ld ms\r\n", inference_time2);

	for (int i=0; i < kCategory; i++)
	{
		fprintf(stderr, "[%d, Prob=%.4f] ", i, output2_probs->data.f[i]);
		sum += output2_probs->data.f[i];
	}
	fprintf(stderr, "\r\n");
	fprintf(stderr, "entropy2=%f\r\n", entropy2);
	printf("Sum: %f\r\n", sum);
	sum = 0.0;

	if (entropy2 < entropy_thresholds[1])
	{
		memcpy(probs, output2_probs->data.f, kCategory*sizeof(probs[0]));
		*exit = 2;
		*entropy = entropy2;
		return;
	}

	// accumulate enough Voltage before proceeding
	//	stop_mode2_duration(ADC_MEASURE_DELAY);
	//	sys_voltage = adc_ref_internal_read();
	charge_status = wait_and_sleep(voltage_thresholds[2]);
	if (charge_status == -1)
	{
		memcpy(probs, output2_probs->data.f, kCategory*sizeof(probs[0]));
		*exit = 2;
		*entropy = entropy2;
		printf("Existing from exit 2 due to low Energy. Results may be INACCURATE!\r\n");
		return;
	}

	// model 3
	// Obtain pointers to the model's input and output tensors
	TfLiteTensor *input3 = interpreter3->input(0);
	//TfLiteTensor *output3_mid_feature = interpreter3->output(0); // Commented out by me
	TfLiteTensor *output3_probs = interpreter3->output(1);
//	for (int i = 0; i < feature2_size; i++) {
//		input3->data.f[i] = output2_mid_feature->data.f[i];
//	}
	// avoid copying
	input3->data.f = output2_mid_feature->data.f;

	error_reporter3->Report("Invoking interpreter3");
	start = HAL_GetTick();
	if (kTfLiteOk != interpreter3->Invoke())
	{
		error_reporter3->Report("Error3");
	}
	inference_time3 = HAL_GetTick() - start;
	*inference_time_total += inference_time3;
	// compute confidence 3
	entropy3 = compute_entropy_normalized(output3_probs->data.f, kCategory);

//	error_reporter3->Report("Showing results3");

	fprintf(stderr, "duration3=%ld ms\r\n", inference_time3);
	for (int i=0; i < kCategory; i++)
	{
		fprintf(stderr, "[%d, Prob=%.4f] ", i, output3_probs->data.f[i]);
		sum += output3_probs->data.f[i];
	}
	fprintf(stderr, "\r\n");
	fprintf(stderr, "entropy3=%f\r\n", entropy3);
	printf("Sum: %f\r\n", sum);
	sum = 0.0;

	{
		memcpy(probs, output3_probs->data.f, kCategory*sizeof(probs[0]));
		*exit = 3;
		*entropy = entropy3;
	}
}

int main_single_event_image(image_t img, float sys_votage)
{
	float probs[kCategory] = {0};
	int32_t exit = 0;
	float entropy = 0;
	uint32_t duration = 0;

	float sys_voltage1, sys_voltage2;

	printf("Start processing\r\n");

	stop_mode2_duration(ADC_MEASURE_DELAY);
	sys_voltage1 = adc_ref_internal_read();
	incremental_inference_with_voltage(img, names1.interpreter, names1.error_reporter, names2.interpreter, names2.error_reporter,
									names3.interpreter, names3.error_reporter,
									probs, &exit, &entropy, &duration);
	stop_mode2_duration(ADC_MEASURE_DELAY);
	sys_voltage2 = adc_ref_internal_read();
	if (exit == -1)
	{
		printf("Low energy! ABORTING\r\n");
	}
	else
	{
		fprintf(stderr, "Exit: %ld, entropy: %f, duration=%ld ms, v1=%.2f, v2=%.2f\r\n", exit, entropy, duration, sys_voltage1, sys_voltage2);
	}
	return 0;
}
