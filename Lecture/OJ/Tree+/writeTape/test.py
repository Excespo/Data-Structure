import os
import subprocess
import argparse

# Params
ProjectName = "writeTape"
InputFile = "in.txt"
MyExecFile = "draft"
RefExecFile = "ref"
MyOutputFile = "out.txt"
RefOutputFile = "out_ref.txt"

PIPE = subprocess.PIPE

def compile_gen_data():
    os.system("g++ -o data_gen.o data_gen.cc")

def generate_data(i):
    if i == 0:
        compile_gen_data()
    os.system("./data_gen.o")

def data_from(read_from):
    subp = subprocess.Popen('cat ./'+ str(read_from), shell = True, stdout = PIPE)
    out, err = subp.communicate()
    # return out
    return out.decode("utf-8")

def execute(exec_name, data, display = False):
    if type(data) == str:
        data = data.encode()
    exec_ = subprocess.Popen('./'+str(exec_name)+'.o', shell = True, stdin = PIPE, stdout = PIPE, stderr = PIPE)
    out, err = exec_.communicate(input=data)

    if display:
        # while exec_.poll() is None:
        #     line = exec_.stdout.readline()
        #     print(line)
        print(out.decode("utf-8"))

def output_from(read_from):
    pass

class Parser:
    def __init__(self):
        # TODO
        pass

if __name__ == "__main__":
    print("Test for\033[5;36m", ProjectName, "\033[0mbegins")
    TEST_STATE = True
    for i in range(50):
        generate_data(i)
        data = data_from(InputFile)
        # print(data)
        execute(MyExecFile, data)
        execute(RefExecFile, data)
        my_res = data_from(MyOutputFile)
        ref_res = data_from(RefOutputFile)
        if my_res != ref_res:
            TEST_STATE = False
            print("\033[1;31mFailed in test round ", i," Given ", my_res, " Expected ", ref_res,"\033[0m")
            print("Test Data is:")
            print(data)
            break

    if TEST_STATE:
        print("\033[1;32mTEST PASSED.\033[0m")
        print("An example to execute \033[1;36m"+MyExecFile+".o\033[0m is :\n")

        execute(MyExecFile, data_from(InputFile), display = True)
        print("\033[7;31mDONT FORGET TO REMOVE OFSTREAM!\033[0m")

