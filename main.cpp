#include <iostream>
#include <sstream>
#include <fstream>
#include <string>


#include "test.pb.h"
//#include "addressbook.pb.h"


#define DESTROY_GG      google::protobuf::ShutdownProtobufLibrary()
#define C_TO_FILE(C,FN) {fstream out(FN,(WB)); C->SerializeToOstream(&out);}
#define C_FROM_FILE(C,FN) {fstream in(FN,(RB)); C->ParseFromIstream(&in);}
#define COUT(C) cout<<C->DebugString()<<endl;

/*

   message SS {
   string  I = 1;
   repeated int32 A = 2;
   }

   message CC {
   repeated SS S = 1;

   }

*/


using namespace std;
using namespace jd;

auto WB = (ios::out|ios::binary|ios::trunc);
auto RB = (ios::in|ios::binary);


// ### sub list ### //

string to_string_(int n)
{
        ostringstream ss;
        ss << n;
        return ss.str();
}
// ### end sub ### //





int main(){
        GOOGLE_PROTOBUF_VERIFY_VERSION;

#define LEN 111111

        auto c = new C();
        auto i = new I();

        for( int ii=0;ii<LEN;ii++ ){

                c->add_s( to_string( ii ).c_str() );

        }

        for( int ii=0;ii<LEN;ii++ ){

                i->add_i( ( ii ) );

        }


        //COUT(c);
        //COUT(i);

        C_TO_FILE(c, "c.bin");
        C_TO_FILE(i, "i.bin");

auto i_ = new I();
        C_FROM_FILE(i_, "i.bin" );

cout<< i_->i(111)<<endl;






        DESTROY_GG;

        return 0;
}


