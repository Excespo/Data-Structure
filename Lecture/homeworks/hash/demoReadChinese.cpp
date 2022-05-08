#include <iostream>
#include <string>
using namespace std;

int main(int argn, char* argc[])
{
	string buf;
	int aLine[100];
	
	while (getline(cin, buf)){
		int nCHN = buf.length()/3, a[3], k, i;
		for (k=0; k<nCHN; k++){ 
			for(i=0; i<3; i++) a[i] = static_cast<unsigned char>(buf[3*k+i]); 
			aLine[k] = a[0]*65536 + a[1]*256 + a[2];
		}
		cout << "* " << buf << "\n";
		cout << nCHN << " Chinese characters : ";
		for (int k=0; k<nCHN; k++) cout << aLine[k] << " ";
		cout << "\n";
	}

	return 0;
}

