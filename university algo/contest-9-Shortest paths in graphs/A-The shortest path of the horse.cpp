#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <type_traits>
#include <assert.h>

using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::pair;
using std::map;
using std::queue;

using Coordinates = pair<int, int>;
using Board = vector<vector<Coordinates>>;

//----------------------------------------------------------------------------//
Coordinates operator+(Coordinates f, Coordinates s) {
    Coordinates result{f.first + s.first, f.second + s.second};
    return result;
}

//----------------------------------------------------------------------------//
Coordinates const empty_Cell = {-1, -1};

struct Game {
    Board board;

    enum Status {
        Continue, Stop
    };

    Coordinates cnv(const string &s) {
        std::map<char, int> cnv_symbol{{'a', 0},
                                       {'b', 1},
                                       {'c', 2},
                                       {'d', 3},
                                       {'e', 4},
                                       {'f', 5},
                                       {'g', 6},
                                       {'h', 7}};
        return {cnv_symbol[s[0]], (s[1] - '1')};
    }


    string cnv(const Coordinates &s) {
        std::map<int, std::string> cnv_symbol{{0, "a"},
                                              {1, "b"},
                                              {2, "c"},
                                              {3, "d"},
                                              {4, "e"},
                                              {5, "f"},
                                              {6, "g"},
                                              {7, "h"}};
        std::string f = (cnv_symbol[s.first]);
        std::string t = std::to_string(s.second + 1);
        std::string res = f + t;
        return res;
    }


    vector<Coordinates> motions = {{-1, -2},
                                   {-1, 2},
                                   {1,  -2},
                                   {1,  2},
                                   {2,  -1},
                                   {2,  1},
                                   {-2, -1},
                                   {-2, 1}};

    Coordinates start_Cell;
    Coordinates finish_Cell;


    bool check(Coordinates pos) {
        if (pos.first < 0 || pos.first > 7 ||
            pos.second < 0 || pos.second > 7) {
            return 0;
        }
        return 1;
    }

    Game() = default;

    Game(string
         str_pos_start, string
         str_pos_finish) : board(8,
                                 vector<Coordinates>(
                                         8,
                                         empty_Cell)),
                           start_Cell(cnv(
                                   str_pos_start)),
                           finish_Cell(cnv(
                                   str_pos_finish)) {}

    void Analysis() {

        queue<Coordinates> q;

        q.push(start_Cell);

        board[start_Cell.first][start_Cell.second] = {-1, -1};

        while (!q.empty()) {
            Coordinates now = q.front();
            q.pop();
            for (auto &move: motions) {
                Coordinates to = now + move;
                if (check(to) && to != start_Cell) {
                    if (board[to.first][to.second] == empty_Cell) {
                        q.push(to);
                        board[to.first][to.second] = now;
                    }
                }
            }
        }

    }

    void write_Cell(Coordinates Cell) {
        if (Cell == empty_Cell) {
            std::cout << "empty_Cell" << std::endl;
            return;
        }
        std::cout << cnv(Cell) << std::endl;
    }

    void Take_route() {
        Coordinates now = finish_Cell;
        std::stack<Coordinates> ans;
        while (now != start_Cell) {
            ans.push(now);
            now = board[now.first][now.second];
        }
        ans.push(start_Cell);
        while (!ans.empty()) {
            write_Cell(ans.top());
            ans.pop();
        }
    }


    ~Game() =
    default;
};


//Coordinates addition test
void Test1() {
    Coordinates a{0, 0}, b{1, 1};
    Coordinates t_1_pair{1, 1};
    if ((a + b) == t_1_pair) {
        assert("Wrong addition of coordinates");
    }
    a = {2, 3};
    b = {-1, 2};
    Coordinates t_2_pair{1, 5};
    if ((a + b) == t_2_pair) {
        assert("Wrong addition of coordinates");
    }
    std::cout << "Test 1 passed." << std::endl;
};

//Empty Cell test
void Test2() {
    std::vector<std::pair<int, int>> mem(10, empty_Cell);
    for (auto &a:mem) {
        if (a != empty_Cell) {
            assert("Wrong init of empty_Cell");
        }
    }
    Coordinates result{2, 2};
    for (auto &a:mem) {
        a = a + empty_Cell;
    }
    for (auto &a:mem) {
        if (a != result) {
            assert("Wrong add of empty_Cell");
        }
    }
    std::cout << "Test 2 passed." << std::endl;
}

//Test of cnv(string) to pos
void Test3() {
    Game game;//
    Coordinates position(game.cnv("a1"));
    Coordinates null_Cell{0, 0};
    if (position != null_Cell) {
        assert("Wrong conversion: a1 to pos");
    }
    position = game.cnv("h8");
    null_Cell = {7, 7};
    if (position != null_Cell) {
        assert("Wrong conversion: h8 to pos");
    }
    position = game.cnv("h1");
    null_Cell = {7, 0};
    if (position != null_Cell) {
        assert("Wrong conversion: h1 to pos");
    }
    position = game.cnv("a8");
    null_Cell = {0, 7};
    if (position != null_Cell) {
        assert("Wrong conversion: a8 to pos");
    }
    std::cout << "Test 3 passed." << std::endl;
}

//Test of cnv(pos) to string
void Test4() {
    Game game;
    std::string position(game.cnv(Coordinates{0, 0}));
    std::string null_Cell("a1");
    if (position != null_Cell) {
        assert("Wrong conversion: 0, 0 to a1");
    }
    position = game.cnv(Coordinates{7, 7});
    null_Cell = "h8";
    if (position != null_Cell) {
        assert("Wrong conversion 7,7 to h8");
    }
    position = game.cnv(Coordinates{7, 0});
    null_Cell = "h1";
    if (position != null_Cell) {
        assert("Wrong conversion 7,0 to h1");
    }
    position = game.cnv(Coordinates{0, 7});
    null_Cell = "a8";
    if (position != null_Cell) {
        assert("Wrong conversion 0,7 to a8");
    }
    std::cout << "Test 4 passed." << std::endl;
}

int main() {

    string str_pos_start, str_pos_finish;

    cin >> str_pos_start;
    cin >> str_pos_finish;

    Game game(str_pos_start, str_pos_finish);


    game.Analysis();
//    for (auto &x:game.board) {
//        for (auto &y:x) {
//            game.write_Cell(y);
//        }
//    }

    game.Take_route();
//    Test1();
//    Test2();
//    Test3();
//    Test4();
}