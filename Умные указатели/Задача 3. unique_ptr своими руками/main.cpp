template <typename T>
class u_ptr {
private:
	T* ptr;
public:
	explicit u_ptr(T* _ptr) : ptr(_ptr) {}
	~u_ptr() { delete ptr; }

	u_ptr(const u_ptr&) = delete;                
	u_ptr& operator= (const u_ptr&) = delete;
	

	T& operator*() { return *ptr; }
	T* operator->() { return ptr; }

	T* release() noexcept{
		T* tmp_ptr = ptr;
		ptr = nullptr;
		return tmp_ptr;
	}

};

int main() {

	return 0;
}