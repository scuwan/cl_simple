#include<CL/cl.h>
#include<stdio.h>
#include<stdlib.h>
//#define BCL_SUCCESS                                  0
//#define CL_DEVICE_NOT_FOUND                         -1
//#define CL_DEVICE_NOT_AVAILABLE                     -2
//#define CL_COMPILER_NOT_AVAILABLE                   -3
//#define CL_MEM_OBJECT_ALLOCATION_FAILURE            -4
//#define CL_OUT_OF_RESOURCES                         -5
//#define CL_OUT_OF_HOST_MEMORY                       -6
//#define CL_PROFILING_INFO_NOT_AVAILABLE             -7
//#define CL_MEM_COPY_OVERLAP                         -8
//#define CL_IMAGE_FORMAT_MISMATCH                    -9
//#define CL_IMAGE_FORMAT_NOT_SUPPORTED               -10
//#define CL_BUILD_PROGRAM_FAILURE                    -11
//#define CL_MAP_FAILURE                              -12
//#define CL_MISALIGNED_SUB_BUFFER_OFFSET             -13
//#define CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST -14
//#define CL_INVALID_VALUE                            -30
//#define CL_INVALID_DEVICE_TYPE                      -31
//#define CL_INVALID_PLATFORM                         -32
//#define CL_INVALID_DEVICE                           -33
//#define CL_INVALID_CONTEXT                          -34
//#define CL_INVALID_QUEUE_PROPERTIES                 -35
//#define CL_INVALID_COMMAND_QUEUE                    -36
//#define CL_INVALID_HOST_PTR                         -37
//#define CL_INVALID_MEM_OBJECT                       -38
//#define CL_INVALID_IMAGE_FORMAT_DESCRIPTOR          -39
//#define CL_INVALID_IMAGE_SIZE                       -40
//#define CL_INVALID_SAMPLER                          -41
//#define CL_INVALID_BINARY                           -42
//#define CL_INVALID_BUILD_OPTIONS                    -43
//#define CL_INVALID_PROGRAM                          -44
//#define CL_INVALID_PROGRAM_EXECUTABLE               -45
//#define CL_INVALID_KERNEL_NAME                      -46
//#define CL_INVALID_KERNEL_DEFINITION                -47
//#define CL_INVALID_KERNEL                           -48
//#define CL_INVALID_ARG_INDEX                        -49
//#define CL_INVALID_ARG_VALUE                        -50
//#define CL_INVALID_ARG_SIZE                         -51
//#define CL_INVALID_KERNEL_ARGS                      -52
//#define CL_INVALID_WORK_DIMENSION                   -53
//#define CL_INVALID_WORK_GROUP_SIZE                  -54
//#define CL_INVALID_WORK_ITEM_SIZE                   -55
//#define CL_INVALID_GLOBAL_OFFSET                    -56
//#define CL_INVALID_EVENT_WAIT_LIST                  -57
//#define CL_INVALID_EVENT                            -58
//#define CL_INVALID_OPERATION                        -59
//#define CL_INVALID_GL_OBJECT                        -60
//#define CL_INVALID_BUFFER_SIZE                      -61
//#define CL_INVALID_MIP_LEVEL                        -62
//#define CL_INVALID_GLOBAL_WORK_SIZE                 -63
//#define CL_INVALID_PROPERTY -64
const char cl_error_code[65][64] =  
{
	"BCL_SUCCESS                                 ", 
	"CL_DEVICE_NOT_FOUND                         ",
	"CL_DEVICE_NOT_AVAILABLE                     ",
	"CL_COMPILER_NOT_AVAILABLE                   ",
	"CL_MEM_OBJECT_ALLOCATION_FAILURE            ",
	"CL_OUT_OF_RESOURCES                         ",
	"CL_OUT_OF_HOST_MEMORY                       ",
	"CL_PROFILING_INFO_NOT_AVAILABLE             ",
	"CL_MEM_COPY_OVERLAP                         ",
	"CL_IMAGE_FORMAT_MISMATCH                    ",
	"CL_IMAGE_FORMAT_NOT_SUPPORTED               ",
	"CL_BUILD_PROGRAM_FAILURE                    ",
	"CL_MAP_FAILURE                              ",
	"CL_MISALIGNED_SUB_BUFFER_OFFSET             ",
	"CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST", 
	"CL_INVALID_VALUE                            ",
	"CL_INVALID_DEVICE_TYPE                      ",
	"CL_INVALID_PLATFORM                         ",
	"CL_INVALID_DEVICE                           ",
	"CL_INVALID_CONTEXT                          ",
	"CL_INVALID_QUEUE_PROPERTIES                 ",
	"CL_INVALID_COMMAND_QUEUE                    ",
	"CL_INVALID_HOST_PTR                         ",
	"CL_INVALID_MEM_OBJECT                       ",
	"CL_INVALID_IMAGE_FORMAT_DESCRIPTOR          ",
	"CL_INVALID_IMAGE_SIZE                       ",
	"CL_INVALID_SAMPLER                          ",
	"CL_INVALID_BINARY                           ",
	"CL_INVALID_BUILD_OPTIONS                    ",
	"CL_INVALID_PROGRAM                          ",
	"CL_INVALID_PROGRAM_EXECUTABLE               ",
	"CL_INVALID_KERNEL_NAME                      ",
	"CL_INVALID_KERNEL_DEFINITION                ",
	"CL_INVALID_KERNEL                           ",
	"CL_INVALID_ARG_INDEX                        ",
	"CL_INVALID_ARG_VALUE                        ",
	"CL_INVALID_ARG_SIZE                         ",
	"CL_INVALID_KERNEL_ARGS                      ",
	"CL_INVALID_WORK_DIMENSION                   ",
	"CL_INVALID_WORK_GROUP_SIZE                  ",
	"CL_INVALID_WORK_ITEM_SIZE                   ",
	"CL_INVALID_GLOBAL_OFFSET                    ",
	"CL_INVALID_EVENT_WAIT_LIST                  ",
	"CL_INVALID_EVENT                            ",
	"CL_INVALID_OPERATION                        ",
	"CL_INVALID_GL_OBJECT                        ",
	"CL_INVALID_BUFFER_SIZE                      ",
	"CL_INVALID_MIP_LEVEL                        ",
	"CL_INVALID_GLOBAL_WORK_SIZE                 ",
	"CL_INVALID_PROPERTY                         "
};

int main() 
{
	// 查询平台
	// clGetPlatformIDs();
	cl_int err = 0;
	cl_platform_id cpis[2];
	err=clGetPlatformIDs(2, cpis, NULL);
	
	// 查询平台信息
	// clGetPlatformInfo();
	size_t size = 0;
	clGetPlatformInfo(cpis[1], CL_PLATFORM_NAME, 0, NULL, &size);
	char *msg = malloc(sizeof(char)*size);
	clGetPlatformInfo(cpis[1], CL_PLATFORM_NAME, size, msg, NULL);
	printf("%s\n", msg);
	free(msg);
	// 查询平台上的设备
	// clGetDeviceIDs();
	cl_device_id cdi1;
	int devicenum;
	err=clGetDeviceIDs(cpis[1],CL_DEVICE_TYPE_GPU,1,&cdi1,NULL);
	clGetDeviceInfo(cdi1, CL_DEVICE_NAME, 0, NULL, &size);
	msg = malloc(sizeof(char)*size);
	clGetDeviceInfo(cdi1, CL_DEVICE_NAME, size, msg, NULL);
	printf("%s\n", msg);
	free(msg);
	
	//创建上下文
	//clCreateContext();
	cl_context ct=clCreateContext(NULL,1,&cdi1,NULL,NULL,&err);
	//cl_context ct=clCreateContextFromType(NULL,CL_DEVICE_TYPE_GPU,NULL,NULL,&err);
	// 创建命令队列
	// clCreateCommandQueue();
	cl_command_queue cq=clCreateCommandQueue(ct,cdi1,0,&err);
	// 读取CL程序源码
	FILE* fp = fopen("add.cl","rb");
	fseek(fp,0,SEEK_END);
	int filesize = ftell(fp);
	fseek(fp,0,SEEK_SET);
	char ch;
	int i = 0;
	char *clcode = (char*)malloc(sizeof(char) * (filesize + 1));
	while((ch=getc(fp)) != EOF)
     	//while((ch=getc(fp)) != 255)
	{
		clcode[i++] = ch;
	}
	clcode[filesize] = '\0';
	fclose(fp);
	printf("%d\n%s\n", filesize, clcode);

	// 创建CL程序
	cl_program cp = clCreateProgramWithSource(ct,1,&clcode,NULL,&err);
	free(clcode);
	// 编译CL程序
	err = clBuildProgram(cp, 1, &cdi1,NULL,NULL,NULL);
	//err = clBuildProgram(cp, 0, NULL,NULL,NULL,NULL);
	// Avoid termination due to CL_BUILD_PROGRAM_FAILURE
	if (err != CL_SUCCESS &&
		err != CL_BUILD_PROGRAM_FAILURE) 
	{
		fprintf(stderr, "Build program abort:\n error code : %d(%s)\n",err, cl_error_code[0-err]);	
		goto clean;
	}
	cl_build_status build_status;
	clGetProgramBuildInfo(cp,
			      cdi1,
			      CL_PROGRAM_BUILD_STATUS,
			      sizeof(cl_build_status),
			      &build_status,
			      NULL);
	if (build_status != CL_SUCCESS)
	{
		char * build_log;
		size_t ret_val_size;
		clGetProgramBuildInfo(cp,
				      cdi1,
				      CL_PROGRAM_BUILD_LOG,
				      0,
				      NULL,
				      &ret_val_size);
		build_log = (char*)malloc(ret_val_size+1);
		clGetProgramBuildInfo(cp,
				      cdi1,
				      CL_PROGRAM_BUILD_LOG,
				      ret_val_size,
				      build_log,
				      NULL);
		build_log[ret_val_size] = '\0';
		fprintf(stderr, "error Build log:\n%s\n",build_log);
		fprintf(stderr, "failed with error code %d (%s)\n\n", build_status, cl_error_code[0-build_status]);
		free(build_log);
		goto clean;
	}
	// 创建内核
	cl_kernel ck = clCreateKernel(cp, "add", &err);
	// 创建buf
	int *a = malloc(sizeof(int)*100);
	int *b= malloc(sizeof(int)*100);
	for (int i = 0; i < 100; i++)
	{
		a[i] = i;
	}
	cl_mem mema = clCreateBuffer(ct,CL_MEM_COPY_HOST_PTR|CL_MEM_READ_ONLY,sizeof(int)*100,a,&err);
	cl_mem memb = clCreateBuffer(ct,CL_MEM_READ_WRITE,sizeof(int)*100,b,&err);
	// 内存推送到GPU
	err = clSetKernelArg(ck, 0, sizeof(cl_mem), &mema);
	err = clSetKernelArg(ck, 1, sizeof(cl_mem), &memb);
	// 计算
	size_t offset[]={0},gws[]={100},lws[]={1};
	clEnqueueNDRangeKernel(cq,ck,1,offset,gws,lws,0,NULL,NULL);
	// 读取计算结果
	err = clEnqueueReadBuffer(cq,memb,CL_TRUE,0,sizeof(int)*100,b,0,NULL,NULL);
	// 输出
	for (int j=0;j<100;j++)
	{
		printf("%4d",b[j]);
		if((j + 1) % 10 == 0 ) printf("\n");
	}
	// clean up
	clReleaseMemObject(mema);
	clReleaseMemObject(memb);
	free(a);
	free(b);
	clReleaseKernel(ck);
clean:
	clReleaseProgram(cp);
	clReleaseCommandQueue(cq);
	clReleaseContext(ct);
	return 0;
}
