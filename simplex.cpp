#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;

//Structure to represent  a row in the simplex tableau
struct Row{
    vector<double>coefficients;
    double solution;
};

//Function to print the simplex tableau 
void printTableau(const vector<Row>%tableau){
    int numCols=tableau[0].coefficients.size();

    //Print column headers
    cout<<setw(10)<<"";
    for(int j=0; j<numCols;++j){
        cout<<setw(10)<<"x"<<j+1;
    }
    cout<<setw(10)<<"Solution"<<endl;

    //Print rows
    for (int=0;i<tableau.size();++i){
        cout<<setw(10)<<"Row"<<i+1<<":";
        for(intj=0;j<numCols;++j){
            cout<<setw(10)<<fixed<<setprecision(2)<<tableau[i].solution<<endl;
        }
    }

    //Function to find the entering variable(pivot column)
    int findEnteringVariable(const vector<Row>&tableau){
        int enteringColumn=-1;
        double minCoeff=0;

        for(int j=0; j<tableau[0].coefficients.size();++j){
            if (tableau[0].coefficients[j]<minCoeff){
                minCoeff=tableau[0].coefficients[j];
                enteringcolumn=j;
            }
        }

        return enteringColumn;
    }

    //Function to find the leaving variable(pivot row)
    int findLeavingVariable(const vector<Row>&tableau, int enteringColumn){
        int leavingRow=-1;
        double minRatio=INT_MAX;

        for(inti=1; i<tableau.size();++i){
            if(tableau[i].coefficients[enteringColumn]>0){
                double ratio=tableau[i].solution/tableau[i].coefficients[enteringColumn];
                if(ratio<minRatio){
                    minRatio=ratio;
                    leavingRow=i;
                }
            }
        }

        return leavingRow;
    }

    //Function to perform the pivot operation
    void pivot(vector<Row>&tableau,int pivotRow, int pivotColumn){
        //Normalize pivot row
        double pivotElement=tableau[pivotRow].coefficients[pivotColumn];
        for(int j=0; j<tableau[pivotRow].coefficients.size()+1;++j){
            tableau[pivotRow].solution/=pivotElement;
        }

        //Eliminate other coefficients in the pivot column
        for(int i=0; i<tableau.size();++i){
            if(i!=pivotRow){
                double factor=tableau[i].coefficients[pivotColumn];
                for(int j=0;j<tableau[i].coefficients.size()+1;++j){
                    tableau[i].coefficients[j]-=factor*tableau[pivotRow].coefficients[j];
                }
            }
        }
    }
    //Function to solve the linear programming problem using the simplex method
    void simplex(vector<Row>&tableau){
        while(true){
            printTableau(tableau);

            int enteringColumn=findEnteringVariable(tableau);

            if (enteringColumn==-1){
                cout<<"Optimal solution found!"<<endl;
                break;
            }

            int LeavingRow=findLeavingVariable(tableau, enteringColumn);

            if(leavingRow==-1){
                cout<<"Unbounded solution"<<endl;
                break;
            }

            pivot(tableau,leavingRow,enteringColumn);
        }
    }

    int main(){
        //Example: Maximize z=3x1+2x2
        //Subject to:
        //x1+x2<=4
        //2x1+x2<=5
        //x1,x2>=0

        vector<Row> tableau={
            {{-3,-2,0,0},0},//Objective function row(maximization)
            {{1,1,1,0},4},
            {{2,1,0,1}5}
        };

        simplex(tableau);

        cout<<"Optimal solution:"<<endl;
        cout<<"x1="<<tableau[1].solution<<endl;
        cout<<"x2="<<tableau[2].solution<<endl;
        cout<<"Optimal value of the objective function:"<<-tableau[0].solution<<endl;

        return 0;
    }
    }