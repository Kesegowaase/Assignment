#include <iostream>
#include <string.h>
using namespace std;

class Text{

private:
	string text[1000];
	int xtimes[1000];
	string text1[1000];

public:
	void camelCase(string word){

		for(int j=0;j<30;j++){

			if(word[j] == '\0')
				break;

			else if( word[j]<= 'Z' && word[j] >= 'A'){

				word[j]=word[j]-'A'+'a';

			}

		}

		static int i=0;
		text[i]=word;
		i++;

	}


	void setRow(int counter){

		for(int j=0;j<counter;j++){

			for(int k=0;k<counter-1;k++){

				if(text[k]>text[k+1]){

					string temp;
					temp=text[k];
					text[k]=text[k+1];
					text[k+1]=temp;

				}

			}

		}

	}

	int cutExcess(int counter){
		int j=0;
		int times =0;
		int wordCounter = 1;
		string word;
		int tempint;
		
		for(;j<counter;j++){

			if(text[j]==word)
				continue;

			word=text[j];
			tempint =j+1;



			for(;tempint<counter;tempint++){
				if(word==text[tempint]){
					wordCounter++;

			}
				}

		text1[times]=word;
		xtimes[times]=wordCounter;
		times++;
		wordCounter=1;
		}

		return times;

	}


	void deleteWord(int number,int counter){

		for(;number<counter-1;number++){

			text[number]=text[number+1];

		}

	}

	void showInfos(int times){
		cout<<"Vocabulary Size = "<<times<<endl;
		for(int i=0;i<times;i++){

			cout<<text1[i]<<" "<<xtimes[i]<<endl;
		}

	}



};

int main(){

	Text text;
	int counter=0;

	while(!cin.eof()){
		string str;
		cin>>str;
		counter++;
		text.camelCase(str);

	}

	text.setRow(counter);

	int times = text.cutExcess(counter);

	text.showInfos(times);


}

