#pragma once

#include "Particle.h"

namespace sahito {
	class Swarm
	{
	public:
		const static int NPARTICLES = 5000;
	private:
		Particle* m_pParticles;
		int lastTime;
	public:
		Swarm();
		void update(int elapsed);
		virtual ~Swarm();
		const Particle* const getParticles() { return m_pParticles; };
	};
}

