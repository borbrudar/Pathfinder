#include <SFML/Graphics.hpp>

using namespace sf;


struct Point {
	Point() = default;
	Point(Vector2f pos, float g, float h)  {
		in(pos, g, h);
	}
	void in(Vector2f pos, float g, float h) {
		this->pos = pos;
		this->g = g;
		this->h = h;
		f = g + h;
	}
	Vector2f pos;
	float g, h, f = 99999;
	int state = 0;
	Vector2f parent;
	bool travel = 1;
};


int main() {

	RenderWindow window;
	window.create(VideoMode(300, 300), "Pathfinder");
	Event e;

	std::vector<std::vector<int>> field;
	std::vector<Point> open;
	std::vector<Point> closed;

	//init field to 0
	field.resize(3);
	for (int i = 0; i < field.size(); i++) { 
		field[i].resize(3); 
		for (int j = 0; j < field[i].size(); j++) field[i][j] = 0;
	}
		
	Vector2f target = Vector2f(2, 0);
	Vector2f start = Vector2f(2, 2);

	open.push_back(Point(start, 0, std::sqrt(std::pow(target.x - start.x, 2) + std::pow(target.y - start.y, 2))));
	
	//find the path
	while (1) {
		//with lowest f
		Point current;
		for (int i = 0; i < open.size(); i++) {
			if (open[i].f < current.f) current = open[i];
		}
		//return if we find the end
		if (current.pos == target) return;

		//check neighbours
		int way = 0; 
		if (way == 0) {
			if (current.pos.x + 1 < field.size()) {

			}
			else way++;
		}
		else way++;
	}

	while (window.isOpen()) {
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed) window.close();
		}
		
		

		//pathfind
		window.clear(Color::White);

		window.display();
	}

	return 0;
}