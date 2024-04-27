
#include "velha.h"

int main()
{
	char velha[3][3] = {
			{'1','2','3'},
			{'4','5','6'},
			{'7','8','9'}
	};

	int player = 1;
	BeginMsg();

	while(true)
	{
		if(player == 1)
		{
			player = 2;
		}
		else
		{
			player = 1;
		}
		if(HasWinned(velha) == true){
			WinText(player);
			break;
		}

		PrintVelha(velha);

		int check = Check();
		if(!updateVelha(check - 1,player,velha)){
			break;
		}

	}
	return 0;
}

