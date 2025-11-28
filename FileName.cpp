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
	if (static_cast<std::size_t>((T.Width * y) + x) >= T.Table.size()) { return nullptr; }
	if (T.Table.size() == 0) { return nullptr; }
	
	return (T.Table)[(T.Width * y) + x];

}

void  Write(Table& T, std::intmax_t x, std::intmax_t y,const Table::DT& D) {
	if (T.Width > x && x < 0) { return; }
	if (T.Height > y && y < 0) { return; }
	if ((unsigned)((T.Width * y) + x) <= T.Table.size()) { return; }
	
	(T.Table)[(T.Width * y) + x]=D;
}

Table::DT MkTblDtErsStr(const std::string& Text) {
	Table::DT T = Text + "@Erased.";
	return T;
}

/** /void Print(Table& T, std::ostream& os) {

	std::intmax_t i = 0;

	os << T.Width << 'x' << T.Height<<std::endl;

	for (auto& o : T.Table) {
		os << o;
		if ((i - T.Width)==0) {
			os<<std::endl;
			i -= T.Width+1;
		}
		else {
			os << ',';
		}
		i++;
	}
}

/**/
void Print(const Table& T,std::ostream& os) {

	for (std::size_t i = 0; i < T.Height; i++) {
		for (std::size_t j = 0; j < T.Width; j++) {
			os << Index(T, j, i);
			os<< ',';
		}
		os << std::endl;
	}
}
Table Row(const Table& T,std::uintmax_t rsp) {

	Table f;
	f.Width = 1;
	f.Height = T.Height;
	for (std::size_t i = 0; i < T.Height; i++) {
		f.Table.push_back(Index(T, rsp, i));
	}

	return f;

}
Table Col(const Table& T,std::uintmax_t csp) {

	Table f;
	f.Width = T.Width;
	f.Height = 1;
	for (std::size_t i = 0; i < T.Width; i++) {
		f.Table.push_back(Index(T, i,csp));
	}

	return f;

}
void Row(const Table& T,std::ostream& os,std::uintmax_t rsp) {

	for (std::size_t i = 0; i < T.Height; i++) {
		os << Index(T, rsp, i) <<std::endl;
	}
}
void Col(const Table& T,std::ostream& os,std::uintmax_t csp) {

	for (std::size_t i = 0; i < T.Width; i++) {
		os<<Index(T, i,csp)<<',';
	}
}
void Clear(Table& In) {
	In.Width = 0;
	In.Height = 0;
	In.Table.clear();
}

int main() {

	Table T = CreatTable(4, 4);

	Print(T, std::cout);

	return 0;
}