float clamp_within_one_two(float min, float value, float max)
{
	return ((value - min) / (max - min)) + 1.0f;
}