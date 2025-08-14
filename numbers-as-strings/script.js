function gt(s1, s2)
{
	if (s1 == s2)
		return false;
	if (s1[0] == '-' && s2[0] == '-')
	{
		s1 = s1.substring(1);
		s2 = s2.substring(1);
		return !gt(s1, s2);
	}
	if (s1[0] == '-')
		return false;
	if (s2[0] == '-')
		return true;
	var l1 = s1.length;
	var l2 = s2.length;
	if (l1 > l2)
		return true;
	if (l1 < l2)
		return false;
	for (var i = 0; i < l1; i++)
	{
		if (s1[i] > s2[i])
			return true;
		if (s1[i] < s2[i])
			return false;
	}
	return false;
}

function sub(s1, s2)
{
	if (s1[0] == '-' && s2[0] == '-')
	{
		s1 = s1.substring(1);
		s2 = s2.substring(1);
		return sub(s2, s1);
	}
	if (s1[0] == '-')
	{
		s1 = s1.substring(1);
		return "-" + add(s1, s2);
	}
	if (s2[0] == '-')
	{
		s2 = s2.substring(1);
		return add(s1, s2);
	}
	if (gt(s2, s1))
		return "-" + sub(s2, s1);
	var i1 = s1.length - 1;
	var i2 = s2.length - 1;
	var a, b, i;
	while (i2 >= 0)
	{
		a = parseInt(s1[i1--]);
		b = parseInt(s2[i2--]);
		if (a < b)
		{
			a += 10;
			for (i = i1; s1[i] == '0'; i--)
				s1 = s1.substring(0, i) + "9" + s1.substring(i + 1);
			s1 = s1.substring(0, i) + (parseInt(s1[i]) - 1).toString() + s1.substring(i + 1);
		}
		s1 = s1.substring(0, i1 + 1) + (a - b).toString() + s1.substring(i1 + 2);
	}
	while (s1[0] == '0')
		s1 = s1.substring(1);
	return s1;
}

function add(s1, s2)
{
	if (s1[0] == '-' && s2[0] == '-')
	{
		s1 = s1.substring(1);
		s2 = s2.substring(1);
		return "-" + add(s1, s2);
	}
	if (s1[0] == '-')
	{
		s1 = s1.substring(1);
		return sub(s2, s1);
	}
	if (s2[0] == '-')
	{
		s2 = s2.substring(1);
		return sub(s1, s2);
	}
	var s3 = "";
	var i1 = s1.length - 1;
	var i2 = s2.length - 1;
	var a, b = 0;
	while (i1 >= 0 || i2 >= 0)
	{
		a = 0;
		if (i1 >= 0)
			a += parseInt(s1[i1--]);
		if (i2 >= 0)
			a += parseInt(s2[i2--]);
		s3 = ((a + b) % 10).toString() + s3;
		b = Math.floor((a + b) / 10);
	}
	if (b > 0)
		s3 = b.toString() + s3;
	return s3;
}

function mult(s1, s2)
{
	if (s1[0] == '-' && s2[0] == '-')
	{
		s1 = s1.substring(1);
		s2 = s2.substring(1);
	}
	if (s1[0] == '-' || s2[0] == '-')
	{
		if (s1[0] == '-')
			s1 = s1.substring(1);
		else
			s2 = s2.substring(1);
		return "-" + mult(s1, s2);
	}
	var s3 = "0", s4, k = 0;
	var a, b, i1, i2 = s2.length;
	while (--i2 >= 0)
	{
		i1 = s1.length - 1;
		b = 0;
		s4 = "";
		while (i1 >= 0)
		{
			a = parseInt(s1[i1--]) * parseInt(s2[i2]);
			s4 = ((a + b) % 10).toString() + s4;
			b = Math.floor((a + b) / 10);
		}
		if (b > 0)
			s4 = b.toString() + s4;
		for (var i = 0; i < k; i++)
			s4 += "0";
		s3 = add(s3, s4);
		k++;
	}
	return s3;
}

function pow(s, e)
{
	const n = s;
	e = parseInt(e) - 1;
	for (var i = 0; i < e; i++)
		s = mult(s, n);
	return s;
}

document.getElementById("out").innerHTML = add("15", "-1000") + ", " + mult("-116", "2") + ", " + pow("-5", 3);
