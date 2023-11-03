# Set the base image to use
FROM gcc:latest
# Copy the C program into the container
COPY prog1.c .
# Compile the C program
RUN gcc -o prog1 prog1.c
# Set the command to run when the container starts
CMD ["./prog1"]