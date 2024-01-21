#include <iostream>
#include <fstream>
#include <string>
#include <vector>


class Observer {
public:
	virtual void onWarning(const std::string& message) {}
	virtual void onError(const std::string& message) {}
	virtual void onFatalError(const std::string& message) {}
};

class Observed {
public:
	
	void AddObserver(Observer* observer) {
		observers_.push_back(observer);
	}

	void RemoveObserver(Observer* observer) {
		auto it = std::remove(observers_.begin(), observers_.end(), observer);
		observers_.erase(it, observers_.end());
	}

	void warning(const std::string& message) const {
		for (const auto& observer : observers_) {
			observer->onWarning(message);
		}
	}

	void error(const std::string& message) const {
		for (const auto& observer : observers_) {
			observer->onError(message);
		}
	}

	void fatalError(const std::string& message) const {
		for (const auto& observer : observers_) {
			observer->onFatalError(message);
		}
	}

	void getQuntityOfObservers() {
		std::cout << "Quantity of observers: " << observers_.size() << std::endl;
	}

private:
	std::vector<Observer*> observers_;
};


// класс для работы с предупреждениями, который будет печатать сообщение в консоль;
class WarningObserver : public Observer {
public:
	void onWarning(const std::string& message) override {
		std::cout << "Warning: " << message << std::endl;
	}
};

// класс для работы с ошибками, который будет печатать сообщение в файл по указанному пути;
class ErrorObserver : public Observer {
public:
	ErrorObserver(const std::string file_name) {
		file_.open(file_name, std::ios::app);
	}
	~ErrorObserver() {
		file_.close();
	}

	void onError(const std::string& message) override {
		if (file_.is_open()){
			file_ << "Error: " << message << std::endl;
		}
	}
	
private:
	std::ofstream file_;
};


// класс для работы с фатальными ошибками, который будет печатать сообщение в консоль и в файл по указанному пути.
class FatalErrorObserver : public Observer {
public:
	FatalErrorObserver(const std::string file_name) {
		file_.open(file_name, std::ios::app);
	}
	~FatalErrorObserver() {
		file_.close();
	}

	void onFatalError(const std::string& message) override {
		if (file_.is_open()){
			file_ << "Fatal error: " << message << std::endl;
		}
		std::cout << "Fatal error: " << message << std::endl;
	}
private:
	std::ofstream file_;
};


int main() {

	Observed obj;

	WarningObserver warning;
	ErrorObserver error("err.txt");
	FatalErrorObserver fatal_err("fatal_err.txt");

	obj.AddObserver(&warning);
	obj.AddObserver(&error);
	obj.AddObserver(&fatal_err);

	
	obj.warning("detected");
	obj.error("detected");
	obj.fatalError("detected");

	obj.getQuntityOfObservers();

	obj.RemoveObserver(&error);

	obj.getQuntityOfObservers();

	return 0;



}