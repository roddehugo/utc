#include "UTProfiler.h"
#include <stdexcept>

void todo(){
	try {
		UVManager& m = UVManager::getInstance();
        m.load("UV_UTC.txt");
		cout<<m.getUV("LO21")<<"\n";
		cout<<m.getUV("NF16")<<"\n";
        //UVManager::libererManager();
        
	}
	catch(UTProfilerException& e){
		cout<<e.getInfo()<<"\n";
	}
	catch(std::exception& e){
		cout<<e.what()<<"\n";
	}

}

int main(){
	//UV uv("LO21","Programmation et conception orientees objet",6,CS);
	//std::cout<<uv<<"\n";
	todo();
	system("pause");
	return 0;
}