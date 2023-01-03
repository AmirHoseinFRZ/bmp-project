#include <stdio.h>
#include <bmpio.h>

void crop_row(int , int );//crop avaliye va hazf ezafe ha

void crop_column(int , int );//crop avaliye va hazf ezafe ha

void white_row(int , int , int , int );//avalin satr har tasvir

void white_column(int , int , int , int );// avalin sotun har tasvir

void crop();//crop nahayi

void resize_row();// resize aval dar jahat "i" ha

void resize_column();// resize dovom dar jahat "j" ha

void func1();//miangin giri o bold kardan

void func2();//crop aks asli

void crop_func2();//crop als vorudi dar tabe func2 o bold kardan khoruji

void resize_column_func2();

void resize_row_func2();

void comparing();//moghyese aks haye vorudi ba miangin ha

char dataset_path[100] = {}, maghsad[100] = {}, path[100] = {}, maghsad2[100] = {}; //masirhaye daryaft o khoruji tasavir
int tedad_sotun = 0, tedad_satr = 0;//tedad satr ha va sotun haye sfid ghabl har tasvir
int noun_w_row[100] = {}, noun_w_column[100] = {};//sart o sotun haye gheir sefid
int width = 0 , hight = 0;
int	w_column[100] = {}, w_row[100] = {};//sart o sotun haye sefid
int f_row = 0, f_column = 0;//sartr o sotun haye crop shode
int s_column = 0, s_row = 0;//satr o sotun haye crop shode
int r1 = 0, r2 = 0, c1 = 0, c2 = 0;//satr ha va sotun haye ghaleb tasavir
unsigned char picture[2000][2000][3] = {}, new_picture[2000][2000][3] = {};// arraye haye crop
int sum[2000][2000][3];// jame piksel ha baraye miangingiri
unsigned char avrage_pic[2000][2000][3] = {}, bold_pic[2000][2000][3] = {};// arraye nahayi func1(miangin giri)
unsigned char new_pic_row[2000][2000][3] = {}, new_pic[2000][2000][3] = {};// arraye haye resize
int new_width = 600, new_hight = 1000;// abaad avaliye va sanaviye aks
unsigned char pic[2000][2000][3] = {}, crop_pic[2000][2000][3] = {};//araye aks voroudi
int ans[10];

int main()
{
	func1();
	func2();
	comparing();
	return 0;
}
void func2()
{
	int m, i, j, x;
	sprintf(path, "test5.bmp");//dadan adres aks vorudi
	readBMP(path, &width, &hight, picture);
	crop_row(width, hight);
	crop_column(width, hight);
	white_row(c1, c2, r1, r2);
	white_column(c1, c2, r1, r2);
	crop_func2();
	for(m = 0; m <= 7; m++)
	{
		sprintf(path, "crop_0%d.bmp", m);// adres aks haye crop shode baraye resize
		readBMP(path, &width, &hight, picture);
		resize_row_func2();
		resize_column_func2();
		for(i = 0; i < new_hight; i++)
		{
			for(j = 0; j < new_width; j++)
			{
				for(x = 0; x < 3; x++)
				{
					if(new_pic[i][j][x] < 150) 	
						new_pic[i][j][x] = 0;
					else
						new_pic[i][j][x] = 255;
				}
			}
		}
		sprintf(maghsad, "(%d).bmp", m);
		saveBMP(new_pic, new_width, new_hight, maghsad);
	}
}
void func1()
{
	int i, j, x, n, m, k, z, ii, jj, xx;
	for(m = 0; m <= 9; m++)
	{
		for(ii = 0; ii < new_hight; ii++)
		{
			for(jj = 0; jj < new_width; jj++)
			{
				for(xx = 0; xx < 3; xx++)
				{
					sum[ii][jj][xx] = 0;
				}
			}
		}
		for(n = 1; n <= 15; n++)
		{
			sprintf(dataset_path, "Dataset\\%d (%d).bmp", m, n);
			readBMP(dataset_path, &width, &hight, picture);
			crop_row(width, hight);
			crop_column(width, hight);
			white_row(c1, c2, r1, r2);
			white_column(c1, c2, r1, r2);
			crop();
			resize_row();
			resize_column();
			for(i = 0; i < new_hight; i++)
			{
				for(j = 0; j < new_width; j++)
				{
					for(x = 0; x < 3; x++)
					{
						sum[i][j][x] += new_pic[i][j][x];// jam kardan hame piksel ha
					}
				}
			}
			for(k = 0; k < new_hight; k++)
			{
				for(z = 0; z < new_width; z++)
				{
					for(x = 0; x < 3; x++)
					{
						avrage_pic[k][z][x] = sum[k][z][x] / 15;//aks miangingiri shode nahati
					}
				}
			}
		}	
		for(k = 0; k < new_hight; k++)
		{
			for(z = 0; z < new_width; z++)
			{
				for(x = 0; x < 3; x++)//bold kardan aks haye miangin
				{
					if( m == 0 && avrage_pic[k][z][x] <= 120)
						avrage_pic[k][z][x] = 0;
					if( m == 1 && avrage_pic[k][z][x] <= 25)
						avrage_pic[k][z][x] = 0;
					if( m == 2 && avrage_pic[k][z][x] <= 99)
						avrage_pic[k][z][x] = 0;	
					if( m == 3 && avrage_pic[k][z][x] <= 121)
						avrage_pic[k][z][x] = 0;
					if( m == 4 && avrage_pic[k][z][x] <= 130)
						avrage_pic[k][z][x] = 0;	
					if( m == 5 && avrage_pic[k][z][x] <= 185)
						avrage_pic[k][z][x] = 0;
					if( m == 6 && avrage_pic[k][z][x] <= 180)
						avrage_pic[k][z][x] = 0;
					if( m == 7 && avrage_pic[k][z][x] <= 220)
						avrage_pic[k][z][x] = 0;
					if( m == 8 && avrage_pic[k][z][x] <= 170)
						avrage_pic[k][z][x] = 0;
					if( m == 9 && avrage_pic[k][z][x] <= 150)
						avrage_pic[k][z][x] = 0;					
				}
			}
		}
		sprintf(maghsad, "%d.bmp", m);
		saveBMP(avrage_pic, new_width, new_hight, maghsad);
	}
}
void crop_row(int width, int hight)
{
	int i, j;
	for(i = 0; i < hight; i++)
	{
		for(j = 0; j < width; j++) 
		{
			if(!(picture[i][j][0] == 255 && picture[i][j][1] == 255 && picture[i][j][2] == 255))
			{
				r1 = i;
			}
		}
	}
	for(i = hight - 1; i >= 0; i--)
	{
		for(j = width - 1; j >= 0; j--) 
		{
			if(!(picture[i][j][0] == 255 && picture[i][j][1] == 255 && picture[i][j][2] == 255))
			{
				r2 = i;
			}
		}
	}
}
void crop_column(int width, int hight)
{
	int i, j;
	for(j = 0; j < width; j++)
	{
		for(i = 0; i < hight; i++) 
		{
			if(!(picture[i][j][0] == 255 && picture[i][j][1] == 255 && picture[i][j][2] == 255))
			{
				c1 = j;
			}
		}
	}
	for(j = width - 1; j >= 0; j--)
	{
		for(i = hight - 1; i >= 0; i--) 
		{
			if(!(picture[i][j][0] == 255 && picture[i][j][1] == 255 && picture[i][j][2] == 255))
			{
				c2 = j;
			}
		}
	}
}
void white_row(int c1, int c2, int r1, int r2)
{
	int i, j, k = 0, ans = 0, n = 0, sum = 0;
	for(i = r2; i <= r1; i++)
	{
		sum=0;
		for(j = c2; j <= c1; j++) 
		{
			if(!(picture[i][j][0] == 255 && picture[i][j][1] == 255 && picture[i][j][2] == 255) && ans == 0)
			{
				noun_w_row[k] = i;		
				ans = 1;
				k++;
			}
			if((picture[i][j][0] == 255 && picture[i][j][1] == 255 && picture[i][j][2] == 255) && ans == 1)
			{
				w_row[n] = i;
				sum++;
				if(sum == c1 - c2 + 1)
				{
					ans = 0;
					n++;
				}			
			}
		}
	}
	tedad_satr = k + 1;
}
void white_column(int c1, int c2, int r1, int r2)
{
	int i, j, k = 0, ans = 0, n = 0, sum = 0;
	for(j = c2; j <= c1; j++)
	{
		sum=0;
		for(i = r2; i <= r1; i++) 
		{
			if(!(picture[i][j][0] == 255 && picture[i][j][1] == 255 && picture[i][j][2] == 255) && ans == 0)
			{
				noun_w_column[k] = j;		
				ans = 1;
				k++;
			}
			if((picture[i][j][0] == 255 && picture[i][j][1] == 255 && picture[i][j][2] == 255) && ans == 1)
			{
				w_column[n] = j;
				sum++;
				if(sum == r1 - r2 + 1)
				{
					ans = 0;
					n++;
				}			
			}
		}
	}
	tedad_sotun = k + 1;
}
void crop()
{
	int i, j, n, k, z, m;
	for(m = 0; m < tedad_satr - 1; m++)
	{
		for(n = 0; n < tedad_sotun - 1; n++)
		{
			for(i = noun_w_row[m]; i <= w_row[m] - 1; i++)
			{
				for(j = noun_w_column[n]; j <= w_column[n] - 1; j++)
				{
					if(!(picture[i][j][0] == 255 && picture[i][j][1] == 255 && picture[i][j][2] == 255))//dar surat vojud piksel gheir sefid edame dahad(baraye rad shodan az faza haye khali
					{
						for(i = noun_w_row[m]; i <= w_row[m] - 1; i++)
						{
							for(j = noun_w_column[n]; j <= w_column[n] - 1; j++)
							{
								if(!(picture[i][j][0] == 255 && picture[i][j][1] == 255 && picture[i][j][2] == 255))
									s_row = i;
							}
						}
						for(i = w_row[m] - 1; i >= noun_w_row[m]; i--)
						{
							for(j = w_column[n] - 1; j >= noun_w_column[n]; j--)
							{
								if(!(picture[i][j][0] == 255 && picture[i][j][1] == 255 && picture[i][j][2] == 255))
								f_row = i;
							}
						}
						for(j = noun_w_column[n]; j <= w_column[n] - 1; j++)
						{
							for(i = noun_w_row[m]; i <= w_row[m] - 1; i++)
							{
								if(!(picture[i][j][0] == 255 && picture[i][j][1] == 255 && picture[i][j][2] == 255))
									s_column = j;
							}
						}
						for(j = w_column[n] - 1; j >= noun_w_column[n]; j--)
						{
							for(i = w_row[m] - 1; i >= noun_w_row[m]; i--)
							{
								if(!(picture[i][j][0] == 255 && picture[i][j][1] == 255 && picture[i][j][2] == 255))
									f_column = j;
							}
						}
						for(i = f_row; i <= s_row; i++)
						{
							for(j = f_column; j <= s_column; j++) 
							{
								for(z = 0; z <= 2; z++)
									new_picture[i - f_row][j - f_column][z] = picture[i][j][z];
							}
						}
					}
				}
			}
		}	
	}
}
void resize_row()
{
	int i, j, k = 0, x;
	double scale = (double)new_width / (double)(s_column - f_column), n = scale;
	for(i = 0; i < s_row - f_row; i++)
	{
		k = 0;
		for(j = 0; j < new_width; j++)
		{	
			if(scale >= 1)
			{
				for(x = 0; x < 3; x++)
				{
					new_pic_row[i][j][x] = new_picture[i][k][x];
				}
				scale = scale - 1;
				if(scale ==  0)
				{
					scale = n;
					k++;
				}	
			}	
			else
			{
				for(x = 0; x < 3; x++)
				{
					new_pic_row[i][j][x] = new_picture[i][k][x] * scale + new_picture[i][k + 1][x] * (1 - scale);
				}
				scale = n + scale - 1;
				k++;
			}
		}
	}
}
void resize_column()
{
	int i, j, k = 0, x;
	double scale = (double)new_hight / (double)(s_row - f_row), n = scale;	
	for(j = 0; j < new_width; j++)
	{
		k = 0;
		for(i = 0; i < new_hight; i++)
		{		
			if(scale >= 1)
			{				
				for(x = 0; x < 3; x++)
				{
					new_pic[i][j][x] = new_pic_row[k][j][x];
				}
				scale = scale - 1;
				if(scale ==  0)
				{
					scale = n;
					k++;
				}		
			}	
			else
			{
				for(x = 0; x < 3; x++)
				{
					new_pic[i][j][x] = new_pic_row[k][j][x] * scale + new_pic_row[k + 1][j][x] * (1 - scale);	
				}
				scale = n + scale - 1;
				k++;
			}
		}
	}
}
void crop_func2()
{
	int i, j, n, k, z, m;
	for(m = 0; m < tedad_satr - 1; m++)
	{
		for(n = 0; n < tedad_sotun - 1; n++)
		{
			for(i = noun_w_row[m]; i <= w_row[m] - 1; i++)
			{
				for(j = noun_w_column[n]; j <= w_column[n] - 1; j++)
				{
					if(!(picture[i][j][0] == 255 && picture[i][j][1] == 255 && picture[i][j][2] == 255))//dar surat vojud piksel gheir sefid edame dahad(baraye rad shodan az faza haye khali
					{
						for(i = noun_w_row[m]; i <= w_row[m] - 1; i++)
						{
							for(j = noun_w_column[n]; j <= w_column[n] - 1; j++)
							{
								if(!(picture[i][j][0] == 255 && picture[i][j][1] == 255 && picture[i][j][2] == 255))
									s_row = i;
							}
						}
						for(i = w_row[m] - 1; i >= noun_w_row[m]; i--)
						{
							for(j = w_column[n] - 1; j >= noun_w_column[n]; j--)
							{
								if(!(picture[i][j][0] == 255 && picture[i][j][1] == 255 && picture[i][j][2] == 255))
								f_row = i;
							}
						}
						for(j = noun_w_column[n]; j <= w_column[n] - 1; j++)
						{
							for(i = noun_w_row[m]; i <= w_row[m] - 1; i++)
							{
								if(!(picture[i][j][0] == 255 && picture[i][j][1] == 255 && picture[i][j][2] == 255))
									s_column = j;
							}
						}
						for(j = w_column[n] - 1; j >= noun_w_column[n]; j--)
						{
							for(i = w_row[m] - 1; i >= noun_w_row[m]; i--)
							{
								if(!(picture[i][j][0] == 255 && picture[i][j][1] == 255 && picture[i][j][2] == 255))
									f_column = j;
							}
						}
						for(i = f_row; i <= s_row; i++)
						{
							for(j = f_column; j <= s_column; j++) 
							{
								for(z = 0; z <= 2; z++)
									new_picture[i - f_row][j - f_column][z] = picture[i][j][z];
							}
						}
						sprintf(maghsad2, "crop_%d%d.bmp", m, n);
						saveBMP(new_picture, s_column - f_column, s_row - f_row, maghsad2);
					}
				}
			}
		}	
	}
}
void resize_row_func2()
{
	int i, j, k = 0, x;
	double scale = (double)new_width / (double)width, n = scale;
	for(i = 0; i < hight; i++)
	{
		k = 0;
		for(j = 0; j < new_width; j++)
		{	
			if(scale >= 1)
			{
				for(x = 0; x < 3; x++)
				{
					new_pic_row[i][j][x] = picture[i][k][x];
				}
				scale = scale - 1;
				if(scale ==  0)
				{
					scale = n;
					k++;
				}	
			}	
			else
			{
				for(x = 0; x < 3; x++)
				{
					new_pic_row[i][j][x] = picture[i][k][x] * scale + picture[i][k + 1][x] * (1 - scale);
				}
				scale = n + scale - 1;
				k++;
			}
		}
	}
}
void resize_column_func2()
{
	int i, j, k = 0, x;
	double scale = (double)new_hight / (double)hight, n = scale;
	for(j = 0; j < new_width; j++)
	{
		k = 0;
		for(i = 0; i < new_hight; i++)
		{		
			if(scale >= 1)
			{				
				for(x = 0; x < 3; x++)
				{
					new_pic[i][j][x] = new_pic_row[k][j][x];
				}
				scale = scale - 1;
				if(scale ==  0)
				{
					scale = n;
					k++;
				}		
			}	
			else
			{
				for(x = 0; x < 3; x++)
				{
					new_pic[i][j][x] = new_pic_row[k][j][x] * scale + new_pic_row[k + 1][j][x] * (1 - scale);	
				}
				scale = n + scale - 1;
				k++;
			}
		}
	}
}
void comparing()//moghyese nahayi
{
	int max, m, i, j, n, k;
	for(m = 0; m < 8; m++)
	{
		for(n = 0; n <= 9; n++)
		{
			ans[n] = 0;
		}
		if(m == 2 || m == 5)
		{
			printf(":");
		}
		else
		{
			for(n = 0; n <= 9; n++)
			{	
				if(m == 0 && n == 3)
					break;
				if(m == 1 && k == 2 && n == 4)
					break;	
				if(m == 3 && n == 6)
					break;
				if(m == 6 && n == 6)
					break;
				sprintf(path, "(%d).bmp", m);//adre aks haye crop va resize shode ye aks vorudi
				readBMP(path, &width, &hight, picture);
				sprintf(path, "%d.bmp", n);//adre aks haye crop va resize shode ye miangin ha
				readBMP(path, &width, &hight, avrage_pic);
				for(i = 0; i < new_hight; i++)
				{
					for(j = 0; j < new_width; j++) 
					{
						if(picture[i][j][0] == 0 && picture[i][j][0] == avrage_pic[i][j][0] && picture[i][j][1] == 0 && picture[i][j][1] == avrage_pic[i][j][1] && picture[i][j][2] == 0 && picture[i][j][2] == avrage_pic[i][j][2])
						{
							ans[n]++;
						}
					}
				}
			}
			max = 0;
			for(n = 0; n <= 9; n++)
			{
				if(max < ans[n])
				{
					max = ans[n];
					k = n;
				}
			}
			printf("%d", k);	
		}
	}
}
