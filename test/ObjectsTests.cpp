#include "ObjectsTests.h"
#include "Objects.h"
#include "Myassert.h"
#include "WasException.h"
#include "Comparison.h"

void ObjectsTests::testObject() {

	object obj;

	obj.setId(3);
	myassert(obj.getId() == 3);

	obj.setName("object");
	myassert((obj.getName() == "object"));

	was_exception(obj.setName(""));
}

void ObjectsTests::testLine() {

	Line line;

	line.setId(1);
	myassert(line.getId() == 1);

	line.setName("myline");
	myassert((line.getName() == "myline"));

	was_exception(line.setName(""));

	vector2D start{ 0, 1 }, end{ 23, -7 };

	line.setStart(start);
	line.setEnd(end);

	myassert((line.getStart() == start));
	myassert((line.getEnd() == end));
	
	myassert(IsEqual(line.getLenth(), 24.351591323771842));
}

void ObjectsTests::testRectangle() {

	Rectangle rec;

	rec.setId(-3);
	myassert(rec.getId() == -3);

	rec.setName("myrectangle");
	myassert((rec.getName() == "myrectangle"));

	was_exception(rec.setName(""));

	rec.setLenth(10.);
	rec.setWidth(10.);
	myassert(IsEqual(rec.getLenth(), 10));
	myassert(IsEqual(rec.getWidth(), 10));

	myassert(IsEqual(rec.getArea(), 100));
	myassert(IsEqual(rec.getPerimetr(), 40));

	was_exception(rec.setLenth(-5));
	was_exception(rec.setWidth(-10));

	vector2D ldp{ -1, 3 };

	rec.setLeftDownPoint(ldp);

	myassert((rec.getLeftDownPoint() == ldp));
}

void ObjectsTests::testCircle() {

	Circle circle;

	circle.setId(19);
	myassert(circle.getId() == 19);

	circle.setName("mycircle");
	myassert((circle.getName() == "mycircle"));

	was_exception(circle.setName(""));

	circle.setRadius(220);
	myassert(IsEqual(circle.getRadius(), 220));

	myassert(IsEqual(circle.getArea(), 152053.084433745992741));

	vector2D center{ 0, 0 };

	circle.setCenter(center);
	myassert((circle.getCenter() == center));

	was_exception(circle.setRadius(-3));

}

void ObjectsTests::testPolyline() {
	
	Polyline polyline;

	polyline.setId(90);
	myassert(polyline.getId() == 90);

	polyline.setName("mypolyline");
	myassert(polyline.getName() == "mypolyline");

	was_exception(polyline.setName(""));


	vector2D point1{ 0, 0 };
	vector2D point2{ 1, 1 };
	vector2D point3{ 2, 2 };
	vector2D point4{ 3, 3 };

	polyline.setPoint(point1);
	polyline.setPoint(point2);
	polyline.setPoint(point3);
	polyline.setPoint(point4);

	vector2D poin5 = polyline.getPoint(0);
	vector2D poin6 = polyline.getPoint(1);
	vector2D poin7 = polyline.getPoint(2);
	vector2D poin8 = polyline.getPoint(3);
	
	myassert((polyline.getPoint(0) == point1));
	myassert((polyline.getPoint(1) == point2));
	myassert((polyline.getPoint(2) == point3));
	myassert((polyline.getPoint(3) == point4));

	myassert(polyline.getPointsCount() == 4);

	was_exception(polyline.getPoint(-1));
	was_exception(polyline.getPoint(10));
}