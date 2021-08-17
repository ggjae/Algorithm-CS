private void move(){
    float _moveDirx = Input.GetAxisRaw("Horizontal");
    float _moveDirz = Input.GetAxisRaw("Vertical");

    Vector3 _moveHori = transform.right * _moveDirx;
    Vector3 _moverVer = transform.forward * _moveDirz;

    Vector3 _vel = (_moveHori + _moverVer).normalized * walkspeed;

    myRigid.MovePosition(transform.position + _vel * Time.deltaTime);
}

private void CharacterRotation(){
    float _yRotation = Input.GetAxisRaw("Mouse X");
    Vector3 _characterRotationY = new Vector3(0f, _yRotation, 0f);
    myRigid.MoveRotation(myRigid.rotation * Quaternion.Euler(_characterRotationY));
}

localEulerAngles => 쿼터니언을 오일러각으로 변환시킨다. (Vector3로 변환)
EulerAngles => 쿼터니언을 오일러각으로 변환.

Quaternion.Euler(Vector3)은 오일러를 쿼터니언으로 변환시킨다.
MoveRotation이나 내장 메소드들이 원하는 값을 얻어내기위하여 서로 왔다갔다 할 수 있어야 함

점프할 때 내가 바닥과 닿아있는지에 대한 함수를 만들 생각이다.

isGround = Physics.Raycast(transform.position, Vector3.down, capsulColider.bounds.extents.y);
transform의 바닥으로 쏴야하는데 transform이 이동하면 안되기때문에 down을 통해서 레이를 쏘게 됨.
바운드의 extents => 총 길이의 반만큼 레이저를 발사하겠다.. 약간의 여유 주려면 +0.1f 해도 됨
닿게되면 true를 반환하겠죠?

Raycast의 return -> 어떤 콜라이더와 레이가 충돌했으면 true, 아니면 false

이 방법보다 rigidbody.velocity.y가 0일때를 확인하면 좋을 듯. 사실 velocity.y는 힘에따라서 
올라갔다가 내려오지만, 0일때 정확하게 누르는게 현실성이 없는 것 같다.

또한 스크립트에 존재하는 start와 update는 존재만으로도 많은 자원을 소모하므로, 사용을 하지 않을시에는
무조건 삭제해주는 게 좋다.

유니티 에디터 - 프로젝트 세팅에 보면 Fire1, Mouse X 등 다양한 종류가 있는데
Input.GetButton("Fire1") 하면 왼쪽버튼 등.. 다양한 이름에 지정되어 있는 Fire1을 찾을 수 있다.

Physics.RayCast(transform.position, transform.forward) 방식처럼 어디 방향으로 쏠지
정할 수 있는데, transform.forward와 같은 방법으로 transform.TransformDirection(Vector3.forward)가
존재한다.
Physics.RayCast(transform.position, transform.forward, out hitInfo, currentHand.range);
range로 범위를 정해줌. 이 때 충돌한게 있다면 return true / 없다면 false

hitInfo.transform.name같은거로 이름을 딸 수도 있다.

camera Depth only는
공간을 투명처리한다.
카메라 두 대 이상을 한 화면에 합성할때 주로 사용한다.
아래 설명해놨지만 카메라의 Viewport를 수정하지 않는 이상 카메라를
10대를 놔도 한화면에 각 카메라의 영상을 가져와서 depth 순서대로 차곡차곡 쌓는다
당연히 화면에 투명한 부분이 없으면 뒤의 화면은 암것도 안보이게 되므로
이러한 처리가 반드시 필요하다
이는 또한 밑에서 설명할 Culling Mask와 같이 사용하는 것이 일반적이다
사용예를 하나 들어보자
적외선모드를 키면 벽넘어의 인물을 보이게 할려고 한다.
이때 벽을 랜더링 속성을 꺼버린다거나 하는 수가 있지만 일일이 벽들을 찾아서
그런 짓을 하기가 번거롭기도 하고 성능상으로도 문제가 될 수 있다
이것을 카메라 두 대로 처리하면 매우 간단히 처리가 된다
메인 카메라와 서브카메라를 두고 서브는
모든 사물의 모습을 끄고 단지 인물만 보이도록 해놓는다
그런 후 서브카메라를 Depth Only 설정으로 두고 켜버리면 벽안에 있든 말든
장소든 상관없이 화면 젤 위에 다 노출되게된다. 

너무 가까우면 짤리는것들을 cliiping planes near을 조정함으로써 설정 가능
culling mask를 이용하여 원하는 레이어만 보이게 카메라를 적용 가능합니다.

보통은 웨폰카메라(너의 팔 상황)와 실제 배경 카메라를 따로 둔다.
그 카메라 두개가 합쳐지면서 예쁘게 보이는 것

layer의 Ignore RayCast를 사용하면 해당 객체를 RayCast는 무시하게 됨