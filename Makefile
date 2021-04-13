all: bank transaction main
	
main:
	g++ Main.cpp Bank.o Account.o BankUser.o Admin.o Standard.o Transaction.o Basic.o AdditionalInfo.o Transfer.o

bank:
	g++ -c Bank.cpp Account.cpp BankUser.cpp Admin.cpp Standard.cpp

transaction:
	g++ -c Transaction.cpp Basic.cpp AdditionalInfo.cpp Transfer.cpp

clean:
	rm a.out Bank.o Account.o BankUser.o Admin.o Standard.o Basic.o AdditionalInfo.o Transaction.o Transfer.o