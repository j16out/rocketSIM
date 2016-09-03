#include "cpress.hpp"

using namespace std;



int main()
{
striset imesh;
string cadfile = "cyl";


load_mesh(imesh, cadfile);

int ff = imesh.mesh.size();

printf("mesh size: %d\n", ff);

	/*for(int i = 0; i < 1; ++i){
	stri temp = imesh.mesh.at(i);
	print_triangle(temp, i);
	}*/


set_limits(imesh);
set_area(imesh);

print_triangle(imesh.mesh.at(0), 0);
print_triangle(imesh.mesh.at(1), 1);
print_triangle(imesh.mesh.at(2), 2);

 return 1;
}








void set_area(striset & imesh)
{

		
	if(imesh.mesh.size() > 1)
	{
	
	for(int i = 0; i < 4; ++i)
		{stri temp;
		temp = imesh.mesh.at(i);
		float area = get_tri_area(temp.vert1,temp.vert2,temp.vert3);
		temp.area = area;
		//cout << "area: " << area << "\n";
		imesh.mesh.at(i) = temp;		
		}
	

	}


}




void set_limits(striset & imesh)
{float i_limH = 0;
 float i_limL = 0;
 float j_limH = 0;
 float j_limL = 0;
 float k_limH = 0;
 float k_limL = 0;
	
	
	
	if(imesh.mesh.size() > 1)
	{stri temp;
		for(int n = 0; n < imesh.mesh.size(); ++n)
		{temp = imesh.mesh.at(n);
			 if(temp.vert1.i > i_limH)
			 i_limH = temp.vert1.i; 
			 
			 if(temp.vert1.i < i_limL)
			 i_limL = temp.vert1.i; 
			 
			 if(temp.vert1.j > j_limH)
			 j_limH = temp.vert1.j; 
			 
			 if(temp.vert1.j < j_limL)
			 j_limL = temp.vert1.j; 
			 
			 if(temp.vert1.k > k_limH)
			 k_limH = temp.vert1.k; 
			 
			 if(temp.vert1.k < k_limL)
			 k_limL = temp.vert1.k; 
			 
			 
			 if(temp.vert2.i > i_limH)
			 i_limH = temp.vert2.i; 
			 
			 if(temp.vert2.i < i_limL)
			 i_limL = temp.vert2.i; 
			 
			 if(temp.vert2.j > j_limH)
			 j_limH = temp.vert2.j; 
			 
			 if(temp.vert2.j < j_limL)
			 j_limL = temp.vert2.j; 
			 
			 if(temp.vert2.k > k_limH)
			 k_limH = temp.vert2.k; 
			 
			 if(temp.vert2.k < k_limL)
			 k_limL = temp.vert2.k; 
			 
			 
			 if(temp.vert3.i > i_limH)
			 i_limH = temp.vert3.i; 
			 
			 if(temp.vert3.i < i_limL)
			 i_limL = temp.vert3.i; 
			 
			 if(temp.vert3.j > j_limH)
			 j_limH = temp.vert3.j; 
			 
			 if(temp.vert3.j < j_limL)
			 j_limL = temp.vert3.j; 
			 
			 if(temp.vert3.k > k_limH)
			 k_limH = temp.vert3.k; 
			 
			 if(temp.vert3.k < k_limL)
			 k_limL = temp.vert3.k; 
	
		}
	 imesh.i_limH = ceil(i_limH*100)/100;
 	 imesh.i_limL = floor(i_limL*100)/100;
 	 imesh.j_limH = ceil(j_limH*100)/100;
	 imesh.j_limL = floor(j_limL*100)/100;
	 imesh.k_limH = ceil(k_limH*100)/100;
	 imesh.k_limL = floor(k_limL*100)/100;	
		
	printf("found limits: %f > x > %f,  %f > y > %f,  %f > z > %f\n", imesh.i_limH, imesh.i_limL, imesh.j_limH, imesh.j_limL, imesh.k_limH, imesh.k_limL);	
		
	}
	else
	{
	 cout << "***Error nothing in mesh****";
	}

}



