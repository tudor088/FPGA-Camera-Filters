#include "hls_video.h"

typedef ap_axiu<24,1,1,1> interface_t;
typedef hls::stream<interface_t> stream_t;

//void edge_detect(stream_t& stream_in, stream_t& stream_out);
void gaussian_blur_compressed2(stream_t& stream_in, stream_t&stream_out);
//void blackwhite_filter(stream_t& stream_in, stream_t& stream_out);
//void invert_image(stream_t& stream_in, stream_t& stream_out);

#define MAX_HEIGHT 720
#define MAX_WIDTH 1280

typedef hls::Mat<MAX_HEIGHT, MAX_WIDTH, HLS_8UC3> rgb_img_t;

#define INPUT_IMAGE "rover.bmp"
#define OUTPUT_IMAGE "rover_output.bmp"
#define OUTPUT_IMAGE2 "rover_output2.bmp"
#define OUTPUT_IMAGE3 "rover_output3.bmp"
#define OUTPUT_IMAGE4 "rover_output4.bmp"

