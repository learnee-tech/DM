#include<iostream>
#include<string>
#include<fstream>
#include<ctype.h>
#include<vector>
#include<math.h>
#include<sstream>
using namespace std;

vector<vector<int>> inputfile(string filename){
 //   string myFilePath = "Cryotherapy.csv";
        ifstream data;
        string temp;
        vector <vector<int>> result;
        data.open(filename);
        if(data.fail()){
            cerr <<" Unable to open the file"<<filename<<endl;
            return result ;
        }
      string records;
      while(data.peek() != EOF){
          getline(data,records);
          cout<<records<<endl;
          //  if(isdigit(records[0]))
        stringstream ss(records);
        vector<int> v;
        string s;
            while(getline(ss,s,',')){
                 stringstream geek(s);
                int x ;
                geek >> x;
                cout<<" x: "<<x;
                    v.push_back(x);
            }
            result.push_back(v);
    }
      data.close();
      return result;


}
int main(){
         string filename;
        cout<<"Enter input file name: ";
        cin>>filename;
        vector <vector<int>> result = inputfile(filename);
        int rows = result.size();
        int cols = result[0].size();
        int row[rows],col[cols];
        for(int i =0;i<result.size();i++){
            int sum_row = 0;
            for(int j=0;j<result[0].size();j++){
                
                sum_row = result[i][j]+sum_row;
            }
             row[i] =sum_row;
            cout<<endl;
        }
        for(int j =0;j<result[0].size();j++){
            int sum_col= 0;
            for(int i=0;i<result.size();i++){
                
                sum_col = result[i][j]+sum_col;
            }
             col[j] =sum_col;
            cout<<endl;
        }
        for(int k =0;k<rows;k++){
            cout<<row[k]<<" ";
        }
        cout<<endl;
        for(int k =0;k<cols;k++){
            cout<<col[k]<<" ";
        }
        ofstream output("out_result.csv");

        //t-weight
         for(int i =0;i<result.size();i++){
            double t = 0;
            for(int j=0;j<result[0].size();j++){
                t = (result[i][j]*100/row[i]);
                output<<"T-weight of "<<result[i][j]<<": "<<t<<"%"<<endl;
            }
            cout<<endl;
        }
        //d-weight
        for(int i =0;i<result.size();i++){
            double d = 0;
            for(int j=0;j<result[0].size();j++){
                d = (result[i][j]*100/col[i]);
                output<<"D-weight of "<<result[i][j]<<": "<<d<<"%"<<endl;
            }
            cout<<endl;
        }

return 0;
}
