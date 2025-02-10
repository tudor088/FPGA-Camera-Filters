#include "stream_header.h"

void blackwhite_filter(stream_t& stream_in, stream_t& stream_out){
	int const rows = MAX_HEIGHT;
	int const cols = MAX_WIDTH;

	rgb_img_t img0(rows, cols);
	rgb_img_t img1(rows, cols);
	rgb_img_t img2(rows, cols);

	hls::AXIvideo2Mat(stream_in, img0);
	hls::CvtColor<HLS_RGB2GRAY>(img0, img1);
	hls::CvtColor<HLS_GRAY2RGB>(img1, img2);
	hls::Mat2AXIvideo(img2, stream_out);
}
