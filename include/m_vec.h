//
//m_vec - componet vector with overrides for basic math for ease of programming
//  Works with both other m_vec and scalar values

#include <iostream>

#ifndef	M_VEC_H
#define	M_VEC_H

class m_vec {
	public:	
		float 	xComp;
		float 	yComp;

		explicit	m_vec(float x = 0, float y = 0);
					~m_vec();
		
		void Set	(float x, float y);
		
		//Basic vector math operations
		//assignment
		m_vec 	&operator=(const m_vec& v);
		m_vec	&operator=(float s);
		//multiply
		m_vec 	operator*	(const m_vec& v) const;
		m_vec	&operator*=	(const m_vec& v);
		m_vec 	operator*	(const float s) const;
		m_vec 	&operator*=	(const float s);
		//divide
		m_vec 	operator/	(const m_vec& v) const;
		m_vec 	&operator/=	(const m_vec& v);
		m_vec 	operator/	(const float s) const;
		m_vec 	&operator/=	(const float s);
		//add
		m_vec 	operator+	(const m_vec& v) const;
		m_vec 	&operator+=	(const m_vec& v);
		m_vec 	operator+	(const float s) const;
		m_vec 	&operator+=	(const float s);
		//subtract
		m_vec 	operator-	(const m_vec& v) const;
		m_vec 	&operator-=	(const m_vec& v);
		m_vec 	operator-	(const float s) const;
		m_vec 	&operator-=	(const float s);

		//Logical Operators
		bool	operator==(const m_vec& v) const;
		bool 	operator!=(const m_vec& v) const;

		//Vector Functions
		
		float 	Magnitude	();					//Returns magnitude of this vector.
		m_vec& 	Normalize	();					//Normalizes and returns this vector.
		m_vec& 	Limit		(float max);		//Limits the force of the vector and returns this vector.
		float 	Distance	(m_vec v);			//Returns distance between two vectors.	
					
		float 	rand_float();					//Produces a random number for vector initalization
};

#endif //M_VEC_H









