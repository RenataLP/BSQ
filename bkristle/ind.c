int check(char *str, char c, int n)
{
	  int i;
	    
	    i = 0;
		  while (i < n)
			    {
					    if (str[i] == c)
							      return (0);
						    i++;
							  }
		    return (1);
}

int union_c(char *str1, char *str2)
{
	  int i;
	    int j;
		  
		  i = 0;
		    j = 0;
			  while (str1[i] != '\0')
				    {
						    if (check(str1, str1[i], i) == 1)
								    {
										     printf("%c", str1[i]);
											      i++;
												       if (str1[i] == str2[j])
														         j++;
													       }
							  }
			    if (str2[j] != '\0')
					  {
						      if (check(str2, str2[j], j) == 1)
								      {
										        printf("%c", str2[j]);
												      j++;
													      }
							    }
				  return (0);
}

int main() {

	  char a[] = "Hello";
	    char b[] = "World";
		  
		  union_c(a, b);
		    return (0);
}
