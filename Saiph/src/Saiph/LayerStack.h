#pragma once

#include "Saiph/Core.h"
#include "Saiph/Layer.h"

namespace Saiph {
	
	class SAIPH_API LayerStack {
	private:
		std::vector<Layer*> m_Layers;
		std::vector<Layer*>::iterator m_LayerInsert;
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer*);
		void PushOverlay(Layer*);
		void PopLayer(Layer*);
		void PopOverlay(Layer*);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }
	};

}
