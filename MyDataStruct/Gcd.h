#ifndef GCD_H
#define GCD_H
class Gcd {
public:
	Gcd();
	~Gcd();
	unsigned int InstanceGcd(int les, int res);
	template<typename T1, typename T2> unsigned int TemplateGcd(T1 t1, T2 t2);
	template<typename T1, typename T2, typename... Args> unsigned int TemplateGcd(T1 t1, T2 t2, Args... rest);
};


template<typename T1, typename T2> 
inline unsigned int Gcd::TemplateGcd(T1 t1, T2 t2) {
	return InstanceGcd(t1, t2);
}


template<typename T1, typename T2, typename... Args>
inline unsigned int Gcd::TemplateGcd(T1 t1, T2 t2, Args... rest) {
	return TemplateGcd(InstanceGcd(t1, t2), rest...);
}

#endif // !GCD_H
