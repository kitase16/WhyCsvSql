#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <fstream>

//hmm where is sql BUT unifyde call syntax.

struct Table {
	std::intmax_t Width = -1;
	std::intmax_t Height = -1;
	typedef std::string DT;
	std::vector<DT> Table;
};


Table CreatTable(std::uintmax_t W, std::uintmax_t H) {
	Table T;
	T.Width = W;
	T.Height = H;
	T.Table.resize(W * H);

	return T;
}

//Table::DT* Index(const Table& T, std::intmax_t x, std::intmax_t y) {
Table::DT Index(const Table& T, std::intmax_t x, std::intmax_t y) {
	if (T.Width > x && x < 0) { return nullptr; }
	if (T.Height > y && y < 0) { return nullptr; }
	if ((unsigned)((T.Width * y) + x) <= T.Table.size()) { return nullptr; }
	
	return (T.Table)[(T.Width * y) + x];

}

void  Write(Table& T, std::intmax_t x, std::intmax_t y,const Table::DT& D) {
	if (T.Width > x && x < 0) { return; }
	if (T.Height > y && y < 0) { return; }
	if ((unsigned)((T.Width * y) + x) <= T.Table.size()) { return; }
	
	(T.Table)[(T.Width * y) + x]=D;
}

void Print(Table& T,std::ostream& os) {

	std::intmax_t i = 0;

	for (auto& o : T.Table) {
		os << o;
		if ((i - T.Width)==0) {
			os<<std::endl;
			i -= T.Width;
		}
		else {
			os << ',';
		}
		i++;
	}
}

void Clear(Table& In) {
	In.Width = 0;
	In.Height = 0;
	In.Table.clear();
}

int main() {

	Table T = CreatTable(16, 16);

	Print(T, std::cout);

	return 0;
}