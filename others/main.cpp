#include <iostream>
#include <iomanip>
using namespace std;

void cal1(const int &N, const double* data, double& mean, double& std){ //使用引用
    double avg = 0;
    double sum = 0;

    for(int i = 0; i < N; i++)
    {
        avg += data[i];
    }

    avg /= N;
    mean = avg;

    for (int i = 0; i < N; i++)
    {
        sum+=(data[i] - avg) * (data[i] - avg);
    }
    std = sum / N;
}

void cal2(int* N, double** data, double* mean, double* std){ //使用指针
        double avg = 0;
        double sum = 0;
    
        for (int i = 0; i < *N; i++)
        {
            avg += (* data)[i];
        }
    
        avg /= *N;
        *mean = avg;
    
        for (int i = 0; i < *N; i++)
        {
            sum += ((*data)[i] - avg) * ((*data)[i] - avg);
        }
    
        *std = sum / *N;
}

int main()
{
    int n;
    cin >> n;
    double *arr = new double[100];; //利用new建立动态数组
    //输入arr
    for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
    double mean, std;
    cal1(n, arr, mean, std); //使用引用
    cout << fixed << setprecision(2) << mean << " " << std << endl;  //保留两位小数 
    cal2(&n, &arr, &mean, &std); //使用指针
    cout << fixed << setprecision(2) << mean << " " << std << endl;
    delete[] arr; //释放arr
    return 0;
}


