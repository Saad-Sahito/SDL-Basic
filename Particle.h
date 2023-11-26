#pragma once
namespace sahito {


	struct Particle
	{
		double m_x;
		double m_y;
	private:
		double m_speed;
		double m_direction;
	private:
		void init();
	public:
		Particle();
		virtual ~Particle();
		void update(int interval);
	};

}