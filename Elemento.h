#pragma once

namespace CaveiraDeCristal
{
	namespace Listas
	{
		template <class TE>
		class Elemento
		{
		private:
			Elemento<TE>* proximo;
			TE* objetoApontado;
		public:
			Elemento(TE* apontado);
			~Elemento();
			void setProximo(Elemento<TE>* seraProximo);
			const Elemento<TE>* getProximo() const;
			const TE* getApontado () const;
		};
	}
}

