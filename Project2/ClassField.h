#pragma once

struct Cells {
	bool isFilled;
	int value;
};

class Game_Field {
private:
	Game_Field();
	~Game_Field();

	Game_Field(const Game_Field&) = delete; //to protect from creating by copy-constructor
	Game_Field& operator=(const Game_Field&) = delete; //to protect from auto-copy

	void* operator new(size_t) = delete; //to protect from creating
	void* operator new[](size_t) = delete;

	void operator delete[](void*) = delete;

	int Size_of_Field;
	Cells* cell;
	bool second_player_is_server;
public:

	static Game_Field& getInstance();
	void change_size_of_field(int new_size);
	bool set_cell_value(int x, int y, int value);
	//void game_process(int size);
	void move_of_player(int player_number);
	void move_of_server(int* x, int* y);
	void set_opponent(bool opponent_type);
	bool opponent_is_server();
	int choose_coordinate(int coord);
	int count_even_summs();
	int count_rows();
	int count_columns();
	int count_diags();
	bool is_filled();

};