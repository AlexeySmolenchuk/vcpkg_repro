#include <OpenImageIO/imageio.h>
#include <iostream>

using namespace OIIO;

int main(int argc, char**argv)
{
	if (argc < 1)
        return 1;

    auto inp = ImageInput::open (argv[1]);
    const ImageSpec &spec = inp->spec();
    std::cout << spec.serialize(ImageSpec::SerialText) << std::endl;

}