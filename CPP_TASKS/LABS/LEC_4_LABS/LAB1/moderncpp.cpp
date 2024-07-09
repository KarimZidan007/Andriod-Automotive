#include <iostream>
#include <string>

enum class ErrorCode
{
Bad_Request=400,
Not_Found=404,
Server_Error=500,
Gateway_Timeout=504
};
void Print_Error(unsigned int Code)
{
    switch (Code) {
        case int (ErrorCode::Bad_Request) : std::cout <<"Bad_Request"; break;
        case int(ErrorCode::Not_Found): std::cout <<"Not_Found";break;
        case int(ErrorCode::Server_Error): std::cout <<"Server_Error"; break;
        case int(ErrorCode::Gateway_Timeout): std::cout <<"Gateway_Timeout"; break;
        default: std::cout<< "Unknown_Error"; break;
		}
	   


}
int main()
{

Print_Error(404);



return 0;
}
