carnival: ride.o magicCarpet.o teacups.o worldTour.o patron.o driver.o
	g++ -o carnival ride.o magicCarpet.o teacups.o worldTour.o patron.o driver.o 

ride.o: ride.cpp ride.h
	g++ -c ride.cpp

magicCarpet.o: MagicCarpet.cpp magicCarpet.h ride.h
	g++ -c MagicCarpet.cpp

teacups.o: Teacups.cpp teacups.h ride.h
	g++ -c Teacups.cpp

worldTour.o: WorldTour.cpp worldTour.h ride.h
	g++ -c WorldTour.cpp

patron.o: patron.cpp patron.h
	g++ -c patron.cpp

driver.o: driver.cpp patron.h ride.h
	g++ -c driver.cpp 

clean:
	rm *.o carnival

