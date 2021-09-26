int clamp_within_zero_one(int min, int value, int max)
{
	return (value - min) / (max - min);
}