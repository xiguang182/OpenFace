import socket
import json


def start_server(port):
    # Create a socket object
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Bind the socket to a specific address and port
    server_socket.bind(('localhost', port))

    # Listen for incoming connections
    server_socket.listen(5)
    print(f"Server listening on port {port}")

    while True:
        # Wait for a client to connect
        client_socket, client_address = server_socket.accept()
        print(f"Connection from {client_address}")

        # Receive data from the client
        data = b''
        while True:
            tmp = client_socket.recv(1024)
            data += tmp
            if len(tmp) < 1024:
                break

        data = data.decode('utf-8')
        # print(f"Received data: {data}")
        json1 = json.loads(data)
        # print(f"Received json: {json1}")
        test = ['face_id', 'frame_number', 'timestamp', 'landmark_detection_success', 
		'landmark_detection_confidence', 'landmarks_2D', 'landmarks_3D', 'pdm_params_local', 'pdm_params_global', 'head_pose',
		'gaze_direction', 'gaze_angle', 'eye_landmarks2D', 'eye_landmarks3D', 'au_intensities', 'au_occurences']
        # print(json1[test])
        for item in test:
            print(item, type(json1[item]), len(json1[item]) if hasattr(json1[item], '__len__') > 0 else 1)

        # You can add your processing logic here

        # Close the connection with the client
        client_socket.close()

if __name__ == "__main__":
    server_port = 8080  # Change this to the desired port
    start_server(server_port)
