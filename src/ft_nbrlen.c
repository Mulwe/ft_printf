int	ft_nbrlen(long long nbr)
{
	int		nbrlen;

	nbrlen = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		nbr = nbr * (-1);
	while (nbr > 0)
	{
		nbrlen++;
		nbr = nbr / 10;
	}
	return (nbrlen);
}
