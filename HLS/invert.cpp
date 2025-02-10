#include "stream_header.h"

void invert_image(stream_t& stream_in, stream_t& stream_out){
	int const rows = MAX_HEIGHT;
	int const cols = MAX_WIDTH;

	rgb_img_t img0(rows, cols);
	rgb_img_t img1(rows, cols);

	hls::AXIvideo2Mat(stream_in, img0);

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			hls::Scalar<3, unsigned char> pixel_in;
			img0 >> pixel_in;

			hls::Scalar<3, unsigned char> pixel_out;
			pixel_out.val[0] = 255 - pixel_in.val[0];
			pixel_out.val[1] = 255 - pixel_in.val[1];
			pixel_out.val[2] = 255 - pixel_in.val[2];

			img1 << pixel_out;
		}
	}

	hls::Mat2AXIvideo(img1, stream_out);
}
