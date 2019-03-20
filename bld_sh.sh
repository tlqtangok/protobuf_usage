set -e
# to bld protobuf 
#./configure --prefix=`pwd`/bld
#make install 

export ROOT_PB=/home/bgi902/t/t/git/protobuf-3.7.0/bin
export PATH=$ROOT_PB/bin:$PATH
export  PKG_CONFIG_PATH=$ROOT_PB/lib/pkgconfig   # NEVER add anything more here !!!
export LD_LIBRARY_PATH=$ROOT_PB/lib:$LD_LIBRARY_PATH

#protoc --cpp_out=. --java_out=. --python_out=. test.proto
protoc --cpp_out=. test.proto
g++ -std=c++11 main.cpp test.pb.cc -o main_test_proto.exe `pkg-config --cflags --libs protobuf`

./main_test_proto.exe 
