#include <iostream>
#include <map>
#include <vector>

class User {
	int _userId;
	std::string _name;
	std::string _email;

public:
	User(int id, std::string name, std::string email) :
		_userId(id), _name(std::move(name)), _email(std::move(email)) {}

	int getUserID() const { return _userId; }
	std::string getUserName() const { return _name; }
	std::string getUserEmail() const { return _email; }
};

class UserManager {
	std::vector<User> _vecUser;

public:
	void addUser(User user) {
		_vecUser.emplace_back(user);
	}
	bool removeUser(User removeuser) {

		auto it = std::find_if(_vecUser.begin(), _vecUser.end(),
			[removeuser](User user) {return user.getUserID() == removeuser.getUserID(); });

		if (it != _vecUser.end()) {
			_vecUser.erase(it);
			return true;
		}
		return false;
	}

	User findUser(int id) {
	
		auto it = std::find_if(_vecUser.begin(), _vecUser.end(),
			[id](User user) {return user.getUserID() == id; });

		if (it != _vecUser.end())
			return *it;
		throw std::runtime_error("User Not found");
	}

	std::vector<User> getAllUser() const {
		return _vecUser;
	}
};

class Room {
	int _roomId;
	int _capacity;
	std::map<time_t, time_t> _bookings; // startTime - endTime

public:
	Room(int id, int capex) : _roomId(id), _capacity(capex) {}

	int getRoomCapacity() const { return _capacity; }
	int getRoomId() const { return _roomId; }

	bool isAvailable(time_t start, time_t end) const {
		for (const auto& [bookedStart, bookedEnd] : _bookings) {
			if (!(bookedStart >= end || bookedEnd <= start)) {
				return false;
			}
		}
		return true;
	}

	bool bookRoom(time_t start, time_t end) {
		if (!isAvailable(start, end)) {
			return false;
		}
		_bookings[start] = end;
		return true;
	}

	void cancelBooking(time_t start) {
		_bookings.erase(start);
	}


};

class RoomManager {
	std::vector<Room> _vecRoom;

public:

	void addRoom(Room room) {
		_vecRoom.emplace_back(room);
	}

	bool removeRoom(int roomId) {
	
		auto it = std::find_if(_vecRoom.begin(), _vecRoom.end(),
			[roomId](Room room) { return room.getRoomId() == roomId; });

		if (it != _vecRoom.end()) {
			_vecRoom.erase(it);
			return true; 
		}
		return false;
	}

	Room findAvailableRoom(time_t start, time_t end, int capacity) {
		for (auto& room : _vecRoom) {
			if (room.isAvailable(start,end) && room.getRoomCapacity() >= capacity)
				return room;
		}
		throw std::runtime_error("No room available");
	}


};

class Meeting {
	int _meetingId;
	Room _room;
	User _meetingOrganizer;
	time_t _startTime;
	time_t _endTime;
	std::vector<User> _vecAttendees;

public:
	Meeting(int id, Room room, User org, time_t start, time_t end) :
		_meetingId(id), _room(room), _meetingOrganizer(org), _startTime(start),
		_endTime(end) {}
	
	void addAttendee(User user) {
		_vecAttendees.push_back(user);

	}

	int getMeetingId() const { return _meetingId; }
	Room getRoom() const { return _room; }
	User getOrganizer() const { return _meetingOrganizer; }
	time_t getStartTime() const { return _startTime; }
	time_t getEndTime() const { return _endTime; }
	std::vector<User> getAttendees() const{ return _vecAttendees; }
};


class MeetingScheduler {
	std::vector<Meeting> _vecMeeting;
	RoomManager roomManager;
	UserManager userManager;
	int nextMeetingId = 1;

public:
	Meeting bookMeeting(time_t start, time_t end, int capacity, int org_id,
		std::vector<int> attendeesId)
	{
		std::cout << "UserManage.size() : " << userManager.getAllUser().size();
		User organizer = userManager.findUser(org_id);

		Room room = roomManager.findAvailableRoom(start, end, capacity);

		Meeting meeting(++nextMeetingId, room, organizer, start, end);

		for (const auto& attendeeIds : attendeesId) {
			User attendee = userManager.findUser(attendeeIds);
			meeting.addAttendee(attendee);
		}

		_vecMeeting.push_back(meeting);

		return meeting;

	}

	bool cancelMeeting(int id) {

		auto it = std::find_if(_vecMeeting.begin(), _vecMeeting.end(),
			[id](Meeting m) {return m.getMeetingId() == id; });

		if (it != _vecMeeting.end()) {

			Meeting mt = *it;
			mt.getRoom().cancelBooking(mt.getStartTime());
			_vecMeeting.erase(it);
			return true;
		}
		return false;
	}

};

int main() {
	MeetingScheduler scheduler;

	UserManager userManage;
	userManage.addUser(User(11, "Anupam", "xyz@gmail.com"));
	userManage.addUser(User(22, "Shubham", "xyz@gmail.com"));
	userManage.addUser(User(33, "Shivam", "xyz@gmail.com"));

	RoomManager roomManage;
	roomManage.addRoom(Room(101, 30));
	roomManage.addRoom(Room(102, 40));
	roomManage.addRoom(Room(103, 50));

	time_t now = time(nullptr);

	try {
		time_t start = now + 3600; // 1 hr from now
		time_t end = start + 1800; // 30 min meeting

		std::cout << "Attempting to book meeting..\n";
		Meeting newMeeting = scheduler.bookMeeting(
			start,
			end,
			35,
			11,
			{22,33}
		);

		std::cout << "Meeting booked successfully..\n";
		
		std::cout << "Meeting Id : " << newMeeting.getMeetingId() << '\n';
		std::cout << "Organizer Id : " << newMeeting.getOrganizer().getUserID() << '\n';
		std::cout << "Room Id : " << newMeeting.getRoom().getRoomId() << '\n';

		std::cout << "Attempting to cancel meeting ..\n";

		if (scheduler.cancelMeeting(newMeeting.getMeetingId())) {
			std::cout << "Meeting cancel successfully...\n";
		}
		else {
			std::cout << "Failed to cancel meeting...\n";
		}

	}
	catch (const std::exception &e) {
		std::cerr << "Error : " << e.what() << '\n';
	}
	return 0;
}