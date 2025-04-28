🗳️ Secure Voting System in C

📜 About the Project

A simple, secure, and lightweight Voting System developed in C language.
This system allows an admin to register up to 100 voters, manage elections, and track votes securely.
It supports three candidates and ensures one person, one vote policy with real-time result updates.

📈 Project Quantified

Feature	Details
🧑‍🤝‍🧑 Max Voters Supported	100 voters
🗳️ Number of Candidates	3 candidates (Alice, Bob, Charlie)
🔐 Admin Password	admin123
🕹️ Voter Authentication	ID-based validation
🔄 Vote Frequency	1 vote per voter (strict)
📄 Persistence	In-memory (no file storage)
⚙️ Compilation Time	~1-2 seconds
🖥️ Execution Time	Real-time

✨ Core Features
	•	🔒 Admin Login (password-protected access)
	•	🧑‍💻 Voter Registration (unique voter IDs)
	•	✅ Single Vote Enforcement (cannot vote twice)
	•	📊 Real-Time Vote Counting
	•	🏆 Result Viewing (shows votes per candidate)
	•	💬 Simple Command-Line Interface (CLI)

🏃‍♂️ Quick Start
	1.	Clone the repository:

git clone https://github.com/yourusername/voting-system-c.git
cd voting-system-c


	2.	Compile the code:

gcc voting_system.c -o voting_system


	3.	Run the application:

./voting_system

📋 Admin Details
	•	Login Password: admin123
	•	Capabilities:
	•	Register voters
	•	View election results
	•	Logout anytime

👥 Candidates

Candidate Number	Name
1	Alice
2	Bob
3	Charlie


🚀 Future Enhancements
	•	Persistent vote saving (to file/database)
	•	Add voter login authentication (password per voter)
	•	Support for more candidates dynamically
	•	Automated winner declaration
	•	Secure encryption for votes and credentials
	•	Graphical User Interface (GUI) version!

📄 License

This project is free to use for educational, personal, or demonstration purposes.
Feel free to fork, modify, and share!

🙌 Thank you for checking out the project!
