#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int n , m;
	printf("Nhap vao so dong mang 2 chieu : ");
	scanf("%d",&n);
	printf("Nhap vao so cot mang 2 chieu : ");
	scanf("%d",&m);
	int numbers[n][m];
	int count , max , min , max_main_diagonal , min_main_diagonal , max_sub_diagonal , min_sub_diagonal;
	int sum;
	do{
		printf("************************MENUU************************** \n");
		printf("1. Nhap gia tri phan tu cua mang \n");
		printf("2. In cac phan tu trong mang theo ma tran \n");
		printf("3. Tinh so luong cac phan tu chia het cho 5 \n");
		printf("4. In cac phan tu co gia tri max , min nam tren duong bien , duong cheo chinh , duong cheo phu \n");
		printf("5. Sap xep cac phan tu giam dan theo dong cua mang \n");
		printf("6. Tinh tong cac phan tu la so nguyen to trong mang \n");
		printf("7. Su dung thuat toan chen sap xep cac phan tu tren duong cheo chinh , duong cheo phu cua mang tang dan \n");
		printf("8. Nhap gia tri 1 mang 1 chieu gom n phan tu vao chi so cot muon chen vao mang 2 chieu \n");
		printf("9. Thoat \n");
		printf("Nhap lua chon : ");
		int choice;
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Nhap cac phan tu cua mang 2 chieu \n");
				for(int i = 0 ; i < n ; i++){
					for(int j = 0 ; j < m ; j++){
						printf("numbers[%d][%d] = ",i,j);
						scanf("%d",&numbers[i][j]);
					}
				}
				printf("\n");
				break;
			case 2 :
				printf("Cac phan tu trong mang theo ma tran \n");
				for(int i = 0 ; i < n ; i++){
					for(int j = 0 ; j < m ; j++){
						printf("%d \t",numbers[i][j]);
					}
					printf("\n");
				}
				printf("\n");
				break;
			case 3:
				count = 0;
				for(int i = 0 ; i < n ; i++){
					for(int j = 0 ; j < m ; j++){
						if(numbers[i][j] % 5 == 0){
							count++;
						}
					}
				}
				printf("So phan tu chia het cho 5 trong mang la %d \n",count);
				break;
			case 4:
				max = numbers[0][0];
				min = numbers[0][0];
				max_main_diagonal = numbers[0][0];
				min_main_diagonal = numbers[0][0];
				max_sub_diagonal = numbers[0][0];
				min_sub_diagonal = numbers[0][0];
				// Gia tri min max tren duong bien
				for(int i = 0 ; i < n ; i++){
					for(int j = 0 ; j < m ; j++){
						if(i == 0 || i == n - 1 || j == 0 || j == m - 1){
							if(numbers[i][j] > max){
								max = numbers[i][j];
							}
							if(numbers[i][j] < min){
								min = numbers[i][j];
							}
						}
					}
				}
				printf("Gia tri max nam tren duong bien la %d \n", max);
				printf("Gia tri min nam tren duong bien la %d \n", min);
				// Gia tri min max nam tren duong cheo chinh
				if(n == m){
					for(int i = 0 ; i < n ; i++){
						for(int j = 0 ; j < m ; j++){
							if(i == j){
								if(numbers[i][j] > max_main_diagonal){
									max_main_diagonal = numbers[i][j];
								}
								if(numbers[i][j] < min_main_diagonal){
									min_main_diagonal = numbers[i][j];
								}
							}
							if(i + j == n - 1){
								if(numbers[i][j] > max_sub_diagonal){
									max_sub_diagonal = numbers[i][j];
								}
								if(numbers[i][j] < min_sub_diagonal){
									min_sub_diagonal = numbers[i][j];
								}
							}
						}
					}
					printf("Gia tri max tren duong cheo chinh la %d \n",max_main_diagonal);
					printf("Gia tri min tren duong cheo chinh la %d \n",min_main_diagonal);
					printf("Gia tri max tren duong cheo phu la %d \n",max_sub_diagonal);
					printf("Gia tri min tren duong cheo phu la %d \n",min_sub_diagonal);
				}else{
					printf("Ma tran khong co duong cheo chinh , duong cheo phu \n");
				}
				break;
			case 5:			
				for(int i = 0; i < n; i++){
					for(int j = 0; j < m - 1; j++){
						for(int k = j + 1; k < m;k++){
							if(numbers[i][j] > numbers[i][k]){
								int temp = numbers[i][j];
								numbers[i][j] = numbers[i][k];
								numbers[i][k] = temp;
							}  
						}
					}
				}
				for(int i = 0; i < n; i++){
					for(int j = 0; j < m; j++){
						printf("%d \t",numbers[i][j]);
					}
					printf("\n");
				}
				break;
			case 6:
				sum = 0;
				for(int i = 0 ; i < n ; i++){
					for(int j = 0 ; j < m ; j++){
						int isPrime = 0;
						if(numbers[i][j] > 2){
							for(int z = 2 ; z < sqrt(numbers[i][j]) ; z++){
								if(numbers[i][j] % z == 0){
									isPrime = 1;
									break;
								}
							}
						}else{
							isPrime = 1;
						}
						if(isPrime == 0){
							printf("%d \t",numbers[i][j]);
							sum += numbers[i][j];
						}
					}
				}
				printf("\n");
				printf("Tong cac so nguyen to trong mang %d \n",sum);
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				exit(0);
			default:
				printf("Vui long nhap lai tu 1 - 9 \n");
		}
	}while(1 == 1);
}
