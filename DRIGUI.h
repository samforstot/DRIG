#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <chrono>
#include <msclr\marshal_cppstd.h>
using namespace std; 
using namespace chrono;

// Global variables so that we only need to read in the data once before we run any algorithms 
int count = 0; 
unordered_map<string, vector<pair<string, vector<int>>>> byTeam;
unordered_map<int, vector<pair<string, vector<int>>>> byYear;
unordered_map<string, vector<pair<string, vector<int>>>> byPlayer;
unordered_map<string, string> nbaTeams = { {"Atlanta Hawks", "ATL"},{"Boston Celtics", "BOS"},{"Brooklyn Nets", "BRK"},{"Charlotte Hornets", "CHO"},{"Chicago Bulls", "CHI"},
			{"Cleveland Cavaliers", "CLE"},{"Dallas Mavericks", "DAL"},{"Dallas Mavericks", "DAL"},{"Denver Nuggets", "DEN"},{"Detroit Pistons", "DET"},{"Golden State Warriors", "GSW"},{"Houston Rockets", "HOU"},
			{"Indiana Pacers", "IND"}, {"Los Angeles Clippers", "LAC"}, {"Los Angeles Lakers", "LAL"}, {"Memphis Grizzlies", "MEM"}, {"Miami Heat", "MIA"}, {"Milwaukee Bucks", "MIL"},
			{"Minnesota Timberwolves", "MIN"}, {"New Orleans Pelicans", "NOP"}, {"New York Knicks", "NYK"}, {"Oklahoma City Thunder", "OKC"}, {"Orlando Magic", "ORL"}, {"Philadelphia 76ers", "PHI"}, {"Phoenix Suns", "PHO"},
			{"Portland Trail Blazers", "POR"}, {"Sacramento Kings", "SAC"}, {"San Antonio Spurs", "SAS"}, {"Toronto Raptors", "TOR"}, {"Utah Jazz", "UTA"},{"Washington Wizards","WAS"} };


// .NET Framework UI 
namespace DRIG {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class DRIGUI : public System::Windows::Forms::Form
	{
	public:
		DRIGUI(void)
		{
			InitializeComponent();
			// Creates 3 maps based on parameters
			LoadData(); 
		} 
	private: System::Windows::Forms::Label^ label2;
	public:

	public:
		int count = 0;

	protected:
		~DRIGUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;


	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::ComboBox^ comboBox3;
	private: System::Windows::Forms::Button^ button1;




	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::ComboBox^ comboBox4;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;




	private: System::Windows::Forms::Label^ label14;
	protected:

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		// Might be some redundant code within this function
		// Lots of controls were used in order to make the UI functional 
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(DRIGUI::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(438, 56);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 52);
			this->label1->TabIndex = 0;
			this->label1->Click += gcnew System::EventHandler(this, &DRIGUI::label1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownHeight = 100;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->IntegralHeight = false;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Player", L"Team", L"Year" });
			this->comboBox1->Location = System::Drawing::Point(39, 214);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 33);
			this->comboBox1->TabIndex = 3;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &DRIGUI::comboBox1_SelectedIndexChanged);
			// 
			// comboBox2
			// 
			this->comboBox2->DropDownHeight = 90;
			this->comboBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->IntegralHeight = false;
			this->comboBox2->Location = System::Drawing::Point(230, 214);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(268, 33);
			this->comboBox2->TabIndex = 4;
			// 
			// comboBox3
			// 
			this->comboBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Field Goals", L"Field Goal Attempts", L"Rebounds",
					L"Assists", L"Steals", L"Blocks", L"Points"
			});
			this->comboBox3->Location = System::Drawing::Point(627, 214);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(204, 33);
			this->comboBox3->TabIndex = 5;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->Location = System::Drawing::Point(507, 314);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(163, 54);
			this->button1->TabIndex = 6;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &DRIGUI::button1_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::RoyalBlue;
			this->label6->Location = System::Drawing::Point(69, 513);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(20, 29);
			this->label6->TabIndex = 11;
			this->label6->Text = L" ";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label6->Click += gcnew System::EventHandler(this, &DRIGUI::label6_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::RoyalBlue;
			this->label7->Location = System::Drawing::Point(375, 513);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(20, 29);
			this->label7->TabIndex = 12;
			this->label7->Text = L" ";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// comboBox4
			// 
			this->comboBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Quick Sort", L"Merge Sort" });
			this->comboBox4->Location = System::Drawing::Point(910, 214);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(162, 33);
			this->comboBox4->TabIndex = 13;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::RoyalBlue;
			this->label8->Location = System::Drawing::Point(549, 513);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(20, 29);
			this->label8->TabIndex = 14;
			this->label8->Text = L" ";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::RoyalBlue;
			this->label9->Location = System::Drawing::Point(1003, 513);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(20, 29);
			this->label9->TabIndex = 15;
			this->label9->Text = L" ";
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->BackColor = System::Drawing::Color::Transparent;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->ForeColor = System::Drawing::Color::RoyalBlue;
			this->label14->Location = System::Drawing::Point(877, 617);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(19, 26);
			this->label14->TabIndex = 20;
			this->label14->Text = L" ";
			this->label14->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label2->Location = System::Drawing::Point(13, 15);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(143, 22);
			this->label2->TabIndex = 21;
			this->label2->Text = L"*Loading in Data";
			// 
			// DRIGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1158, 756);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->comboBox4);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"DRIGUI";
			this->Text = L"D.R.I.G.";
			this->Load += gcnew System::EventHandler(this, &DRIGUI::DRIGUI_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		// Function to load in the data ONE TIME as soon as the program is opened
		void LoadData(void) {
			cout << "Starting up the D.R.I.G." << endl << "This might take a moment...";
			if (count == 0) {
				fstream file;
				string data;
				file.open("DaData3.txt");
				getline(file, data);
				while (getline(file, data, ',')) {
					getline(file, data, ',');//Date
					string dateTemp = data;
					dateTemp.erase(4, 1);
					dateTemp.erase(6, 1);
					int date = stoi(dateTemp);
					int year = stoi(dateTemp.substr(0, 4));
					getline(file, data, ',');
					getline(file, data, ',');
					getline(file, data, ',');// Team Abbreviation: Ex: CHI
					string team = data;
					getline(file, data, ',');
					getline(file, data, ',');
					getline(file, data, ',');
					getline(file, data, ',');
					getline(file, data, ',');
					getline(file, data, ',');
					getline(file, data, ',');
					getline(file, data, ',');
					getline(file, data, ',');
					getline(file, data, ',');
					getline(file, data, ',');
					getline(file, data, ',');
					getline(file, data, ',');
					getline(file, data, ',');
					getline(file, data, ',');
					getline(file, data, ','); // Player name: Ex: Lebron James
					string playerName = data;
					getline(file, data, ',');// Player codes: Ex: jalevine01
					string player = data;
					getline(file, data, ',');
					getline(file, data, ',');
					getline(file, data, ',');// Field Goals Made(fg)
					int fg = stoi(data);
					getline(file, data, ',');// Field Goals Attempted (fga)
					int fga = stoi(data);
					getline(file, data, ',');
					getline(file, data, ',');
					getline(file, data, ',');
					getline(file, data, ',');
					getline(file, data, ',');//ft
					getline(file, data, ',');//fta
					getline(file, data, ',');
					getline(file, data, ',');
					getline(file, data, ',');
					getline(file, data, ',');// Rebounds
					int rebounds = stoi(data);
					getline(file, data, ',');// Assists
					int assists = stoi(data);
					getline(file, data, ',');// Steals
					int steals = stoi(data);
					getline(file, data, ',');// Blocks
					int blocks = stoi(data);
					getline(file, data, ',');
					getline(file, data, ',');
					getline(file, data, ',');// Points
					int points = stoi(data);
					byPlayer[playerName].push_back({ team, { fg, fga, rebounds, assists, steals, blocks, points, date } });
					byYear[year].push_back({ team + playerName, { fg, fga, rebounds, assists, steals, blocks, points, date } });
					byTeam[team].push_back({ playerName, { fg, fga, rebounds, assists, steals, blocks, points, date } });
					getline(file, data);
				}
				cout << "\nInitialization complete." << endl;
			}
		}
#pragma endregion
	// Change the items in each comboBox based off the index to set parameters
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		// Ensures all of the data is NOT read in another time
		count++; 
		label2->Text = "";
		// userInput alligns with the specifc parameter and map that will be used for the algorithm
		int userInput = comboBox1->SelectedIndex;
		fstream file; 
		// Players
		if (userInput == 0) {
			comboBox2->Items->Clear();
			string getName; 
			file.open("PlayerList.txt", ios::in);
			while (getline(file, getName)) {
				String^ playerName = gcnew String(getName.c_str());
				comboBox2->Items->Add(playerName);
			}
			file.close(); 
		}
		// Teams
		else if (userInput == 1) {
			comboBox2->Items->Clear(); 
			string getTeam; 
			file.open("nbaTeams.txt", ios::in);
			while (getline(file, getTeam)) {
				String^ teamName = gcnew String(getTeam.c_str());
				comboBox2->Items->Add(teamName);
			}
			file.close(); 
		
		}
		// Years
		else if (userInput == 2) {
			comboBox2->Items->Clear();
			comboBox2->Items->Add("2019");
			comboBox2->Items->Add("2020");
			comboBox2->Items->Add("2021");
			comboBox2->Items->Add("2022");
		}

	}
// Once the button is clicked, take in all values and perform the algorithm
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	int mapType = comboBox1->SelectedIndex; 
	String^ mapValue;
	string stdMapValue;
	if (comboBox2->SelectedItem != nullptr) {
		mapValue = comboBox2->SelectedItem->ToString();
		msclr::interop::marshal_context context;
		stdMapValue = context.marshal_as<string>(mapValue);
	}

	int statType = comboBox3->SelectedIndex;
	int sortType = comboBox4->SelectedIndex;

	// Makes sure the index for each search is not out of range
	if (mapType == -1 || comboBox2->SelectedIndex == -1 || statType == -1 || sortType == -1) {
		label2->Text = "*Please fill out every parameter!";
	}
	// Perform algorithm with parameters
	else {
		calculateData(mapType, stdMapValue, statType, sortType);
		label2->Text = "";
	}
}

// Merge Sort Algorithm
void merge(vector<pair<string, vector<int>>>& data, int start, int mid, int end, int index) {
    vector<pair<string, vector<int>>> temp;
    int i, j;
    i = start;
    j = mid + 1;
    while (i <= mid && j <= end) {
        if (data[i].second.at(index) <= data[j].second.at(index)) {
            temp.push_back(data[i]);
            i++;
        }
        else {
            temp.push_back(data[j]);
            j++;
        }
    }
    while (i <= mid) {
        temp.push_back(data[i]);
        i++;
    }
    while (j <= end) {
        temp.push_back(data[j]);
        j++;
    }
    for (int i = start; i <= end; i++)
        data[i] = temp[i - start];

}
void mergeSort(vector<pair<string, vector<int>>>& data, int start, int end, int index) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(data, start, mid, index);
        mergeSort(data, mid + 1, end, index);
        merge(data, start, mid, end, index);
    }
}

// Quick Sort Algorithm
void quickSort(vector<pair<string, vector<int>>>& data, int low, int high, int index) {
    int i = low;
    int j = high;
    int mid = low + (high - low) / 2;
    int pivot = data[mid].second.at(index);

    while (i < high || j > low) {
        while (data[i].second.at(index) < pivot) {
            i++;
        }
        while (data[j].second.at(index) > pivot) {
            j--;
        }

        if (i <= j) {
            swap(data[i], data[j]);
            i++;
            j--;
        }
        else {
            if (i < high) {
                quickSort(data, i, high, index);
            }
            if (j > low) {
                quickSort(data, low, j, index);
            }
            return;
        }
    }

}
// Overwrites maps in order to perform the sort from scratch and get accurate reading of time it takes
private: System::Void calculateData(int mapType, string mapValue, int statType, int sortType) {
	unordered_map<string, vector<pair<string, vector<int>>>> teamMap;
	unordered_map<int, vector<pair<string, vector<int>>>> yearMap;
	unordered_map<string, vector<pair<string, vector<int>>>> playerMap;

	playerMap = byPlayer;
	teamMap = byTeam; 
	yearMap = byYear; 

	String^ time;
	if (mapType == 0) {
		// By Player
		// Quick Sort
		if (sortType == 0) {
			auto start = high_resolution_clock::now();
			quickSort(playerMap[mapValue], 0, playerMap[mapValue].size() - 1, statType);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			time = duration.count() + " ms";

		}
		// Merge Sort
		else if (sortType == 1) {
			auto start = high_resolution_clock::now();
			mergeSort(playerMap[mapValue], 0, playerMap[mapValue].size() - 1, statType);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			time = duration.count() + " ms";
		}
		// Output
		int date = playerMap[mapValue][playerMap[mapValue].size() - 1].second.at(7);
		string sdate = to_string(date);
		sdate.insert(4, "-");
		sdate.insert(7, "-");
		String^ realDate = gcnew String(sdate.c_str());
		label6->Text = realDate;

		string teamName = playerMap[mapValue][playerMap[mapValue].size() - 1].first;
		String^ teamNameS = gcnew String(teamName.c_str());
		label7->Text = teamNameS;

		String^ playerName = gcnew String(mapValue.c_str());
		label8->Text = playerName;

		int stat = playerMap[mapValue][playerMap[mapValue].size() - 1].second.at(statType);
		string stringstat = to_string(stat);
		String^ realStat = gcnew String(stringstat.c_str());
		label9->Text = realStat; 

		label14->Text = time;

	}
	else if (mapType == 1) {
		// By Team
		string teamNameABV = nbaTeams[mapValue];

		// Quick Sort
		if (sortType == 0) {
			auto start = high_resolution_clock::now();
			quickSort(teamMap[teamNameABV], 0, teamMap[teamNameABV].size() - 1, statType);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			time = duration.count() + " ms";
		}
		// Merge Sort
		else if (sortType == 1) {
			auto start = high_resolution_clock::now();
			mergeSort(teamMap[teamNameABV], 0, teamMap[teamNameABV].size() - 1, statType);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			time = duration.count() + " ms";
		}
		// Output
		int date = teamMap[teamNameABV][teamMap[teamNameABV].size() - 1].second.at(7);
		string sdate = to_string(date);
		sdate.insert(4, "-");
		sdate.insert(7, "-");
		String^ realDate = gcnew String(sdate.c_str());
		label6->Text = realDate;

		
		String^ teamNameS = gcnew String(teamNameABV.c_str());
		label7->Text = teamNameS;
		
		string sPlayerName = teamMap[teamNameABV][teamMap[teamNameABV].size() - 1].first;
		String^ playerName = gcnew String(sPlayerName.c_str());
		label8->Text = playerName;
		
		int stat = teamMap[teamNameABV][teamMap[teamNameABV].size() - 1].second.at(statType);
		string stringstat = to_string(stat);
		String^ realStat = gcnew String(stringstat.c_str());
		label9->Text = realStat;

		label14->Text = time;

	}
	else if (mapType == 2) {
		// By Year
		int season = stoi(mapValue);

		// Quick Sort
		if (sortType == 0) {
			auto start = high_resolution_clock::now();
			quickSort(yearMap[season], 0, yearMap[season].size() - 1, statType);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			time = duration.count() + " ms";
		}
		// Merge Sort
		else if (sortType == 1) {
			auto start = high_resolution_clock::now();
			mergeSort(yearMap[season], 0, yearMap[season].size() - 1, statType);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			time = duration.count() + " ms";
		}
		//Output
		int date = yearMap[season][yearMap[season].size() - 1].second.at(7);
		string sdate = to_string(date);
		sdate.insert(4, "-");
		sdate.insert(7, "-");
		String^ realDate = gcnew String(sdate.c_str());
		label6->Text = realDate;


		string teamName = yearMap[season][yearMap[season].size() - 1].first.substr(0, 3);
		String^ teamNameS = gcnew String(teamName.c_str());
		label7->Text = teamNameS;

		string sPlayerName = yearMap[season][yearMap[season].size() - 1].first.substr(3);
		String^ playerName = gcnew String(sPlayerName.c_str());
		label8->Text = playerName;

		int stat = yearMap[season][yearMap[season].size() - 1].second.at(statType);
		string stringstat = to_string(stat);
		String^ realStat = gcnew String(stringstat.c_str());
		label9->Text = realStat;
		label14->Text = time;
	}
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void DRIGUI_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
