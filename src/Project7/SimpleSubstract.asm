@7		//PUSH CONSTANT
D=A
@SP
A=M
M=D
@SP
M=M+1
@8		//PUSH CONSTANT
D=A
@SP
A=M
M=D
@SP
M=M+1
@SP			//begin Substract command 
M=M-1
A=M
D=M
@SP
M=M-1
A=M
D=D-M
@SP
A=M
M=D
@SP
M=M+1		//end Substract command
