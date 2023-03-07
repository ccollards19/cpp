
template <typename T>
void iter(T *tab, int len, void(*f)(T &arg))
{
	int i = 0;
	while (i < len)
	{
		f(tab[i]);
		i++;
	}
}
