unsigned int	get_max_length(char **map) // Might wanna move this
{
	t_resolution	pos;
	unsigned int	save;


	pos.height = 0;
	save = 0;
	while (map[pos.height])
	{
		pos.width = 0;
		while (map[pos.height][pos.width])
			pos.width += 1;
		if (pos.width > save) 
			save = pos.width;
		pos.height += 1;
	}
	return (save);
}
