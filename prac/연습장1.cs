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