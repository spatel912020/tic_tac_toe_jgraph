#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	double x, y;
	char turn; 
	int command = 0;
	vector <string> prev_command;
	printf("newgraph\n");
	printf("xaxis min 0 max 3 hash 1 mhash 0  no_draw_axis grid_lines\n");
	printf("no_auto_hash_labels no_draw_hash_marks\n");
	printf("yaxis min 0 max 3 hash 1 mhash 0  no_draw_axis grid_lines\n");
	printf("no_auto_hash_labels no_draw_hash_marks\n");
	while(cin>>turn>>x>>y){
        if(command != 0){
            printf("copygraph\n");
            printf("x_translate %d\n", (command/3)*4);
            printf("y_translate %d\n", (command%3)*-4);
        }
		for(int i = 0; i < prev_command.size(); i++){
			cout<<prev_command[i]<<endl;
		}
		x += 0.5;
		y += 0.5;
		if(turn == 'X'){
			string cur_command = "newcurve eps cross.ps marksize 1 1 pts " + to_string(x) + " " + to_string(y);
			printf("newcurve eps cross.ps marksize 1 1 pts %f %f\n", x, y);
			prev_command.push_back(cur_command);
		}
		else{
			string cur_command = "newcurve eps circle.ps marksize 1 1 pts " + to_string(x) + " " + to_string(y);
			printf("newcurve eps circle.ps marksize 1 1 pts %f %f\n", x, y);
			prev_command.push_back(cur_command);
		}
		printf("\n\n");
		command++;
	}
	return 0;
}
