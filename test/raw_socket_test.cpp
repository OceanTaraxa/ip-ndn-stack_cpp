#include "../helper/RawSocketHelper.cpp"
using namespace std;

unsigned char data[1024] = {
        0x45, 0x00, 0x00, 0x3c, 0x7c, 0x9b, 0x00, 0x00,
		0x80, 0x01, 0x39, 0x8e, 0xc0, 0xa8, 0x48, 0x53,
		0x00, 0x01, 0x01, 0x01, 0x08, 0x00, 0x43, 0x52,
		0x00, 0x01, 0x0a, 0x09, 0x61, 0x62, 0x63, 0x64,
		0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c,
		0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74,
		0x75, 0x76, 0x77, 0x61, 0x62, 0x63, 0x64, 0x65,
		0x66, 0x67, 0x68, 0x69};

int main() {
    //创建套接字
    RawSocketHelper rawSocketHelper;
    int len = 60;
    for(int i = 0; i < len; i++) {
        cout << data[i] << ", ";
    }

    sockaddr sockaddr;
    rawSocketHelper.sendPacketTo(&data, len, 0);
//    send(sockfd, )
    return 0;
}

